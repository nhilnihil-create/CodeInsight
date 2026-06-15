import { useState, useMemo } from 'react';
import { motion } from 'framer-motion';
import GlassPanel, {
  GlassPanelHeader,
  GlassPanelTitle,
  GlassPanelContent,
} from '@/components/ui/glass-panel';
import GlassDivider from '@/components/ui/glass-divider';
import SegmentedPicker from '@/components/ui/segmented-picker';
import { KNOWLEDGE_AREA_GROUPS, buildRadarDataForGroup } from '@/data/knowledgeAreaConcepts';
import ConceptRadarChart from '@/components/concept-radar/ConceptRadarChart';

const pickerOptions = KNOWLEDGE_AREA_GROUPS.map((g) => ({
  key: g.key,
  label: g.shortLabel,
}));

export default function ConceptRadarPanel({ scores = [], loading = false }) {
  const [selectedArea, setSelectedArea] = useState('SDF-FPC');

  const radarData = useMemo(
    () => buildRadarDataForGroup(scores, selectedArea),
    [scores, selectedArea],
  );

  const currentGroup = KNOWLEDGE_AREA_GROUPS.find((g) => g.key === selectedArea);
  const totalConcepts = radarData.length;
  const attemptedConcepts = radarData.filter((d) => d.attempts > 0).length;

  return (
    <GlassPanel interactive className="h-full">
      <GlassPanelHeader>
        <div className="flex items-center gap-2">
          <GlassPanelTitle>Concept Radar</GlassPanelTitle>
          <span className="text-[10px] font-mono uppercase tracking-wider text-muted-foreground/50">
            {loading ? 'Loading...' : `${attemptedConcepts}/${totalConcepts} concepts`}
          </span>
        </div>
      </GlassPanelHeader>
      <GlassPanelContent className="p-0">
        <div className="px-5 pt-4 pb-2">
          <SegmentedPicker
            value={selectedArea}
            onChange={setSelectedArea}
            options={pickerOptions}
            size="sm"
          />
          <p className="text-[10px] text-muted-foreground/50 mt-2 ml-0.5 font-mono tracking-wide">
            {currentGroup?.label}
          </p>
        </div>
        <GlassDivider />
        <motion.div
          key={selectedArea}
          initial={{ opacity: 0, scale: 0.95 }}
          animate={{ opacity: 1, scale: 1 }}
          transition={{ duration: 0.3, ease: [0.25, 0.46, 0.45, 0.94] }}
          className="h-72 w-full"
        >
          <ConceptRadarChart data={radarData} />
        </motion.div>
      </GlassPanelContent>
    </GlassPanel>
  );
}
