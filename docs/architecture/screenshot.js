const { chromium } = require('playwright');
const path = require('path');

(async () => {
  // argv[2] = html filename (default: dark), argv[3] = png filename (default: dark)
  const htmlName = process.argv[2] || 'codeinsight-v2-architecture.html';
  const pngName = process.argv[3] || 'codeinsight-v2-architecture.png';
  const htmlPath = path.resolve(__dirname, htmlName);
  const pngPath = path.resolve(__dirname, pngName);

  const browser = await chromium.launch();
  const page = await browser.newPage({ viewport: { width: 1587, height: 1123 } });

  await page.goto('file://' + htmlPath, { waitUntil: 'networkidle' });

  // Wait a moment for fonts/layout
  await page.waitForTimeout(500);

  // Screenshot the canvas element at full size
  const canvas = await page.$('#canvas');
  await canvas.screenshot({ path: pngPath });

  console.log('PNG saved to:', pngPath);
  await browser.close();
})().catch((err) => {
  console.error('Screenshot failed:', err);
  process.exit(1);
});