const canvas = document.querySelector('canvas');
const ctx = canvas.getContext('2d');
const span = document.getElementById('score');

const screenWidth = canvas.width;
const screenHeight = canvas.height;
const img = new Image();
let lastTime = 0;

const randomRange = (min, max) =>
  Math.floor(Math.random() * (max - min + 1) + min);

const getFPS = () => {
  let now = performance.now();
  let frameTime = (now - lastTime).toFixed(2);
  lastTime = now;
  span.innerText = 'FPS: ' + Math.round(1000 / Number(frameTime));
};

const loop = () => {
  window.requestAnimationFrame(loop);
  ctx.clearRect(0, 0, screenWidth, screenHeight);
  for (let i = 0; i < 5000; i++) {
    ctx.drawImage(img, randomRange(0, 400), randomRange(0, 400));
  }
  getFPS();
};

window.addEventListener('load', () => {
  img.src = './texture.png';
  window.requestAnimationFrame(loop);
});
