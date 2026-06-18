import { useRef, useEffect, useState } from 'react';
import GlowCard from './GlowCard';

function StaggerItem({ children, delay = 0, visible }) {
  return (
    <div
      style={{ transitionDelay: `${delay}ms` }}
      className={`transition-all duration-500 ease-out ${
        visible ? 'opacity-100 translate-y-0' : 'opacity-0 translate-y-4'
      }`}
    >
      {children}
    </div>
  );
}

export default function FeatureRow({ icon: Icon, title, description, details, visual, reverse = false }) {
  const ref = useRef(null);
  const [visible, setVisible] = useState(false);

  useEffect(() => {
    const el = ref.current;
    if (!el) return;
    const observer = new IntersectionObserver(
      ([entry]) => {
        if (entry.isIntersecting) {
          setVisible(true);
          observer.disconnect();
        }
      },
      { threshold: 0.1, rootMargin: '0px 0px -50px 0px' }
    );
    observer.observe(el);
    return () => observer.disconnect();
  }, []);

  return (
    <div
      ref={ref}
      className={`grid items-center gap-8 lg:gap-16 transition-all duration-700 ease-out ${
        visible ? 'opacity-100 translate-y-0' : 'opacity-0 translate-y-16'
      } ${reverse ? 'lg:grid-cols-[1fr_1.2fr]' : 'lg:grid-cols-[1.2fr_1fr]'}`}
    >
      {/* Visual / Mockup */}
      <StaggerItem delay={reverse ? 200 : 0} visible={visible} className={reverse ? 'lg:order-2' : ''}>
        <GlowCard className="p-6">
          {visual}
        </GlowCard>
      </StaggerItem>

      {/* Text */}
      <div className={`space-y-4 ${reverse ? 'lg:order-1' : ''}`}>
        <StaggerItem delay={0} visible={visible}>
          <div className="inline-flex h-11 w-11 items-center justify-center rounded-lg bg-primary/10 text-primary transition-transform duration-300 hover:scale-110 hover:rotate-3">
            <Icon className="h-5 w-5" />
          </div>
        </StaggerItem>

        <StaggerItem delay={100} visible={visible}>
          <h3 className="text-2xl font-bold tracking-tight">{title}</h3>
        </StaggerItem>

        <StaggerItem delay={200} visible={visible}>
          <p className="text-muted-foreground leading-relaxed">{description}</p>
        </StaggerItem>

        {details && (
          <ul className="space-y-2 text-sm text-muted-foreground">
            {details.map((d, i) => (
              <StaggerItem key={i} delay={300 + i * 80} visible={visible}>
                <li className="flex items-start gap-2 group">
                  <span className="mt-1.5 h-1.5 w-1.5 shrink-0 rounded-full bg-primary transition-transform duration-200 group-hover:scale-150" />
                  <span className="transition-colors duration-200 group-hover:text-foreground">{d}</span>
                </li>
              </StaggerItem>
            ))}
          </ul>
        )}
      </div>
    </div>
  );
}
