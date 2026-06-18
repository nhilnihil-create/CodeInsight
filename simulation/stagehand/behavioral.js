/**
 * simulation/stagehand/behavioral.js
 *
 * Behavioral simulation engine that simulates real user interactions:
 *   - Realistic keystroke timing
 *   - Tab switching events
 *   - Paste events
 *   - Idle time periods
 *   - Mouse movements and clicks
 */

const { BASE_URL } = require('./config');

/**
 * Simulate realistic typing with per-character delays.
 * @param {any} page - Playwright page
 * @param {string} selector - CSS selector for the input/editor
 * @param {string} text - Text to type
 * @param {number} speed - Base ms per keystroke
 */
async function simulateTyping(page, text, speed = 100) {
  // Use Monaco editor API if available, otherwise fall back to direct typing
  const hasMonaco = await page.evaluate(() => !!window.monaco).catch(() => false);

  if (hasMonaco) {
    // Inject code via Monaco API (instant, but we track the "virtual" typing time)
    await page.evaluate((code) => {
      const models = window.monaco.editor.getModels();
      if (models.length > 0) {
        models[0].setValue(code);
      }
    }, text);
  } else {
    // Fallback: use Playwright typing with delay
    const editor = page.locator('.monaco-editor, textarea, [contenteditable="true"]').first();
    if (await editor.isVisible({ timeout: 3000 }).catch(() => false)) {
      await editor.click();
      await page.keyboard.type(text, { delay: speed });
    }
  }
}

/**
 * Simulate tab switching behavior.
 * @param {any} page - Playwright page
 * @param {number} count - Number of tab switches to simulate
 */
async function simulateTabSwitches(page, count) {
  for (let i = 0; i < count; i++) {
    // Simulate Alt+Tab behavior
    await page.evaluate(() => {
      document.dispatchEvent(new KeyboardEvent('keydown', { key: 'Tab', altKey: true }));
    });
    await page.waitForTimeout(100);
  }
}

/**
 * Simulate paste events.
 * @param {any} page - Playwright page
 * @param {number} count - Number of paste events to simulate
 * @param {string} content - Content being pasted
 */
async function simulatePasteEvents(page, count, content = '') {
  for (let i = 0; i < count; i++) {
    await page.evaluate((text) => {
      const editor = document.querySelector('.monaco-editor, textarea');
      if (editor) {
        const pasteEvent = new ClipboardEvent('paste', {
          bubbles: true,
          cancelable: true,
          clipboardData: new DataTransfer()
        });
        pasteEvent.clipboardData.setData('text/plain', text || 'pasted code');
        editor.dispatchEvent(pasteEvent);
      }
    }, content);
    await page.waitForTimeout(50);
  }
}

/**
 * Simulate idle time (no user activity).
 * @param {any} page - Playwright page
 * @param {number} seconds - Seconds to simulate idle
 */
async function simulateIdleTime(page, seconds) {
  const waitMs = Math.min(seconds * 1000, 5000); // Cap at 5 seconds for testing
  await page.waitForTimeout(waitMs);
}

/**
 * Simulate mouse movements and clicks (double clicks).
 * @param {any} page - Playwright page
 * @param {number} doubleClicks - Number of double clicks to simulate
 */
async function simulateMouseActivity(page, doubleClicks) {
  const editor = page.locator('.monaco-editor, textarea').first();
  if (await editor.isVisible({ timeout: 3000 }).catch(() => false)) {
    for (let i = 0; i < doubleClicks; i++) {
      await editor.dblclick({ force: true }).catch(() => {});
      await page.waitForTimeout(100);
    }
  }
}

/**
 * Simulate behavioral telemetry events via API.
 * @param {any} page - Playwright page
 * @param {Object} behavior - Behavior configuration
 */
async function sendBehavioralTelemetry(page, behavior) {
  await page.evaluate((data) => {
    fetch('/api/student/behavioral-events', {
      method: 'POST',
      headers: { 'Content-Type': 'application/json' },
      body: JSON.stringify({
        eventType: 'session_summary',
        exerciseId: window.location.pathname.split('/').pop(),
        data: {
          tabSwitches: data.tabSwitches,
          pasteEvents: data.pasteEvents,
          idleTime: data.idleTime,
          doubleClicks: data.doubleClicks,
        },
      }),
    }).catch(() => {});
  }, behavior);
}

/**
 * Run full behavioral simulation for a persona.
 * @param {any} page - Playwright page
 * @param {Object} persona - Persona with behavior config
 */
async function simulateFullBehavior(page, persona) {
  const { behavior } = persona;

  // Simulate tab switching
  if (behavior.tabSwitches > 0) {
    await simulateTabSwitches(page, behavior.tabSwitches);
  }

  // Simulate paste events
  if (behavior.pasteEvents > 0) {
    await simulatePasteEvents(page, behavior.pasteEvents);
  }

  // Simulate idle time
  if (behavior.idleTime > 0) {
    await simulateIdleTime(page, behavior.idleTime);
  }

  // Simulate mouse activity
  if (behavior.doubleClicks > 0) {
    await simulateMouseActivity(page, behavior.doubleClicks);
  }

  // Send behavioral telemetry
  await sendBehavioralTelemetry(page, behavior);
}

module.exports = {
  simulateTyping,
  simulateTabSwitches,
  simulatePasteEvents,
  simulateIdleTime,
  simulateMouseActivity,
  sendBehavioralTelemetry,
  simulateFullBehavior,
};
