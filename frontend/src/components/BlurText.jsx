import { useEffect, useRef } from 'react';

export default function BlurText({ text, delay = 0, className = '' }) {
  const ref = useRef(null);

  useEffect(() => {
    const el = ref.current;
    if (!el) return;

    const words = text.split(' ');
    el.innerHTML = words
      .map((word, i) =>
        `<span class="blur-word" style="display:inline-block; opacity:0; filter:blur(8px); transform:translateY(20px); transition:opacity 0.6s ease ${delay + i * 0.08}s, filter 0.6s ease ${delay + i * 0.08}s, transform 0.6s ease ${delay + i * 0.08}s;">${word}</span>`
      )
      .join(' ');

    const observer = new IntersectionObserver(
      ([entry]) => {
        if (entry.isIntersecting) {
          el.querySelectorAll('.blur-word').forEach(w => {
            w.style.opacity = '1';
            w.style.filter = 'blur(0)';
            w.style.transform = 'translateY(0)';
          });
          observer.disconnect();
        }
      },
      { threshold: 0.1 }
    );

    observer.observe(el);
    return () => observer.disconnect();
  }, [text, delay]);

  return <span ref={ref} className={className} />;
}
