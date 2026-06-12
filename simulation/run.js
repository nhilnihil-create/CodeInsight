#!/usr/bin/env node
/**
 * simulation/run.js
 *
 * Main entry point for Tier A simulation.
 * Usage: node run.js
 *
 * Runs: cleanup → setup → baseline → stress → adversarial → CDS trigger
 *
 * Mode: DIRECT DB (no Docker). Submissions are written directly to the database
 * with simulated pass/fail results based on persona behavior profiles.
 * This tests the CDS engine, integrity flags, and data aggregation without
 * spinning up Docker compiles for each submission.
 *
 * Memory guard: heap capped at SIM_MAX_MEM_MB (default 512MB).
 * Forces GC between cycles, halts if limit exceeded.
 */

require('dotenv').config({ path: '../backend/.env', quiet: true });

const { cleanup, setup, runBaseline, runStress, runAdversarial, triggerCDS } = require('./automationRunner');

(async function main() {
  const startTime = Date.now();

  try {
    await cleanup();
    const ctx = await setup();
    const baselineResults = await runBaseline(ctx);
    if (global.gc) { global.gc(); console.log('\n♻️  GC after baseline cycle'); }
    const stressResults = await runStress(ctx);
    if (global.gc) { global.gc(); console.log('\n♻️  GC after stress cycle'); }
    const adversarialResults = await runAdversarial(ctx);
    if (global.gc) { global.gc(); console.log('\n♻️  GC after adversarial cycle'); }

    await triggerCDS(ctx.client, ctx.exercises.baseline.id);
    await triggerCDS(ctx.client, ctx.exercises.stress.id);
    await triggerCDS(ctx.client, ctx.exercises.adversarial.id);

    const elapsed = ((Date.now() - startTime) / 1000).toFixed(1);
    const memUsage = process.memoryUsage();
    const heapMB = Math.round(memUsage.heapUsed / 1024 / 1024);
    const rssMB = Math.round(memUsage.rss / 1024 / 1024);
    console.log('\n📊 SIMULATION SUMMARY');
    console.log('='.repeat(60));
    console.log(`   Total time: ${elapsed}s`);
    console.log(`   Students: ${ctx.students.length}`);
    console.log(`   Memory: heap=${heapMB}MB, rss=${rssMB}MB`);
    console.log(`   Baseline: ${baselineResults.totalSubmissions} submissions, ${baselineResults.totalPasses} passes`);
    console.log(`   Stress:   ${stressResults.totalSubmissions} submissions, ${stressResults.totalPasses} passes`);
    console.log(`   Adversarial: ${adversarialResults.totalSubmissions} submissions, ${adversarialResults.totalPasses} passes`);
    console.log(`   Infinite loops caught: ${stressResults.infiniteLoopsCaught}`);
    console.log(`   Section ID: ${ctx.section.id}`);
    console.log(`   Instructor: ${ctx.instructor.email}`);
    console.log('='.repeat(60));
    console.log('\n✅ Simulation complete. Run validator: node validator.js\n');

  } catch (err) {
    console.error('\n❌ Simulation failed:', err.message);
    console.error(err.stack);
    process.exit(1);
  }
})();
