#!/usr/bin/env node
/**
 * Project CodeNet C++ Concept Tagging Scanner — Memory Safe
 *
 * Spawns a fresh Node.js process for each batch of 50 problems.
 * This ensures tree-sitter native memory is fully freed between batches.
 *
 * Usage: node scripts/codenet-scanner.js
 */

const fs = require('fs');
const path = require('path');
const { execSync } = require('child_process');

const DATA_DIR = path.resolve(__dirname, '..', 'data', 'Project_CodeNet_C++1000');
const OUTPUT_FILE = path.resolve(__dirname, '..', 'data', 'concept_mapping.json');
const BATCH_SIZE = 50;

function main() {
  if (!fs.existsSync(DATA_DIR)) {
    console.error('Error: data/Project_CodeNet_C++1000/ not found');
    process.exit(1);
  }

  const problemDirs = fs.readdirSync(DATA_DIR)
    .filter(d => fs.statSync(path.join(DATA_DIR, d)).isDirectory()).sort();

  console.log(`CodeNet C++ Concept Scanner (batch mode)`);
  console.log(`=========================================`);
  console.log(`${problemDirs.length} problems, batch size ${BATCH_SIZE}`);
  console.log(`Each batch runs in a separate process (max 512MB heap)`);
  console.log();

  // Write problem list for workers
  const listFile = path.resolve(__dirname, '..', 'data', '_scan_list.json');
  fs.writeFileSync(listFile, JSON.stringify(problemDirs));

  const batches = [];
  for (let i = 0; i < problemDirs.length; i += BATCH_SIZE) {
    batches.push(problemDirs.slice(i, i + BATCH_SIZE));
  }

  console.log(`Batches: ${batches.length}\n`);

  const allResults = {};
  const dist = {};
  const start = Date.now();

  for (let b = 0; b < batches.length; b++) {
    const batchFile = path.resolve(__dirname, '..', 'data', `_batch_${b}.json`);
    fs.writeFileSync(batchFile, JSON.stringify(batches[b]));

    const batchStart = Date.now();
    try {
      const result = execSync(
        `node --max-old-space-size=512 scripts/codenet-worker.js ${batchFile}`,
        {
          cwd: path.resolve(__dirname, '..'),
          maxBuffer: 50 * 1024 * 1024,
          timeout: 300000,
          env: { ...process.env, NODE_ENV: 'production' }
        }
      );

      const batchData = JSON.parse(result.toString());
      Object.assign(allResults, batchData);

      for (const [pid, tags] of Object.entries(batchData)) {
        for (const t of tags) {
          const key = t.charAt(0).toUpperCase() + t.slice(1);
          if (dist[key] === undefined) dist[key] = 0;
          dist[key]++;
        }
      }

      // Clean up batch file
      try { fs.unlinkSync(batchFile); } catch {}

      const elapsed = ((Date.now() - batchStart) / 1000).toFixed(1);
      console.log(`  Batch ${b + 1}/${batches.length}: ${batches[b].length} problems in ${elapsed}s`);
    } catch (err) {
      console.error(`  Batch ${b + 1} FAILED: ${err.message.substring(0, 200)}`);
      try { fs.unlinkSync(batchFile); } catch {}
    }

    // Force GC hint
    if (global.gc) global.gc();
  }

  // Write final output
  fs.writeFileSync(OUTPUT_FILE, JSON.stringify(allResults, null, 2), 'utf8');

  // Clean up
  try { fs.unlinkSync(listFile); } catch {}

  const totalElapsed = ((Date.now() - start) / 1000).toFixed(1);
  const tagged = Object.values(allResults).filter(t => t.length > 0).length;

  console.log(`\n=========================================`);
  console.log(`${problemDirs.length} problems scanned, ${tagged} tagged in ${totalElapsed}s`);
  console.log(`\nDistribution:`);
  for (const [c, count] of Object.entries(dist)) {
    console.log(`  ${c}: ${count} (${((count / problemDirs.length) * 100).toFixed(1)}%)`);
  }
  console.log(`\n→ ${OUTPUT_FILE}`);
}

if (require.main === module) main();
