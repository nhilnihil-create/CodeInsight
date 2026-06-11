#!/usr/bin/env node
/**
 * simulation/run.js
 *
 * Main entry point for Tier A simulation.
 * Usage: node run.js
 *
 * Runs: cleanup → setup → baseline → stress → adversarial → CDS trigger
 */

require('dotenv').config({ path: '../backend/.env' });

const { cleanup, setup, runBaseline, runStress, runAdversarial, triggerCDS } = require('./automationRunner');

(async function main() {
  const startTime = Date.now();

  try {
    await cleanup();
    const ctx = await setup();
    const baselineResults = await runBaseline(ctx);
    const stressResults = await runStress(ctx);
    const adversarialResults = await runAdversarial(ctx);

    await triggerCDS(ctx.client, ctx.exercises.baseline.id);
    await triggerCDS(ctx.client, ctx.exercises.stress.id);
    await triggerCDS(ctx.client, ctx.exercises.adversarial.id);

    const elapsed = ((Date.now() - startTime) / 1000).toFixed(1);
    console.log('\n📊 SIMULATION SUMMARY');
    console.log('='.repeat(60));
    console.log(`   Total time: ${elapsed}s`);
    console.log(`   Students: ${ctx.students.length}`);
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
