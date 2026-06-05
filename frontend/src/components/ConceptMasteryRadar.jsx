import { useEffect, useRef } from 'react';
import * as d3 from 'd3';
import { cn } from '@/lib/utils';

const CONCEPTS = ['DT', 'VR', 'CD', 'LP', 'FN', 'AR', 'OP'];
const FULL_NAMES = {
  DT: 'Datatypes', VR: 'Variables', CD: 'Conditionals',
  LP: 'Loops', FN: 'Functions', AR: 'Arrays', OP: 'OOP',
};
const CDS_COLORS = { low: '#22C55E', mod: '#FACC15', high: '#EF4444', na: '#7C3AED' };

function cdsColor(val) {
  if (val == null) return CDS_COLORS.na;
  if (val <= 0.31) return CDS_COLORS.low;
  if (val <= 0.50) return CDS_COLORS.mod;
  if (val <= 0.66) return CDS_COLORS.high;
  return CDS_COLORS.na;
}

export default function ConceptMasteryRadar({ mastery, classAverage, view = 'student', width = 300, height = 300, className }) {
  const svgRef = useRef(null);

  useEffect(() => {
    if (!svgRef.current) return;

    const svg = d3.select(svgRef.current);
    svg.selectAll('*').remove();

    const margin = 40;
    const radius = Math.min(width, height) / 2 - margin;
    const centerX = width / 2;
    const centerY = height / 2;

    const angleSlice = (2 * Math.PI) / CONCEPTS.length;
    const rScale = d3.scaleLinear().domain([0, 1]).range([0, radius]);

    const g = svg.append('g').attr('transform', `translate(${centerX}, ${centerY})`);

    [0.25, 0.5, 0.75, 1].forEach((v) => {
      g.append('circle')
        .attr('r', rScale(v))
        .attr('fill', 'none')
        .attr('stroke', 'hsl(213 41% 22%)')
        .attr('stroke-width', 0.5)
        .attr('stroke-dasharray', '3,3');
    });

    CONCEPTS.forEach((c, i) => {
      const angle = angleSlice * i - Math.PI / 2;
      g.append('line')
        .attr('x1', 0).attr('y1', 0)
        .attr('x2', rScale(1) * Math.cos(angle))
        .attr('y2', rScale(1) * Math.sin(angle))
        .attr('stroke', 'hsl(213 41% 22%)')
        .attr('stroke-width', 1);

      const labelR = rScale(1) + 18;
      g.append('text')
        .attr('x', labelR * Math.cos(angle))
        .attr('y', labelR * Math.sin(angle))
        .attr('text-anchor', 'middle')
        .attr('dominant-baseline', 'middle')
        .attr('class', 'text-[10px] fill-muted-foreground font-mono')
        .text(c);
    });

    function plotPolygon(data, fill, stroke, opacity = 0.3) {
      const points = CONCEPTS.map((c, i) => {
        const angle = angleSlice * i - Math.PI / 2;
        const val = data[c] ?? 0;
        return [rScale(val) * Math.cos(angle), rScale(val) * Math.sin(angle)];
      });

      const lineGen = d3.line().x(d => d[0]).y(d => d[1]);

      g.append('path')
        .datum([...points, points[0]])
        .attr('d', lineGen)
        .attr('fill', fill)
        .attr('fill-opacity', opacity)
        .attr('stroke', stroke)
        .attr('stroke-width', 2)
        .attr('stroke-opacity', 0.8);
    }

    if (classAverage) {
      plotPolygon(classAverage, '#7C3AED', '#7C3AED', 0.1);
      g.append('text')
        .attr('x', radius * Math.cos(-Math.PI / 2 + 0.1) - 10)
        .attr('y', radius * Math.sin(-Math.PI / 2 + 0.1) - 5)
        .attr('class', 'text-[9px] fill-[#7C3AED]')
        .text('class avg');
    }

    const dataColor = view === 'student' ? '#22C55E' : '#85D2D0';
    plotPolygon(mastery, dataColor, dataColor, 0.25);

    const entries = CONCEPTS.map(c => ({ concept: c, value: mastery[c] ?? 0 }));
    const lowest = entries.reduce((min, e) => e.value < min.value ? e : min, entries[0]);
    if (lowest) {
      const idx = CONCEPTS.indexOf(lowest.concept);
      const angle = angleSlice * idx - Math.PI / 2;
      const pt = [rScale(lowest.value) * Math.cos(angle), rScale(lowest.value) * Math.sin(angle)];
      g.append('circle')
        .attr('cx', pt[0]).attr('cy', pt[1])
        .attr('r', 5)
        .attr('fill', '#EF4444')
        .attr('stroke', '#EF4444')
        .attr('stroke-width', 2);
    }

  }, [mastery, classAverage, view, width, height]);

  return (
    <div className={cn('flex flex-col items-center', className)}>
      <svg ref={svgRef} width={width} height={height} className="w-full" />
      {view === 'student' && (
        <p className="text-[10px] text-muted-foreground mt-1">
          Shaded: your mastery · Inner ring: class average
        </p>
      )}
    </div>
  );
}

export { CONCEPTS, FULL_NAMES };
