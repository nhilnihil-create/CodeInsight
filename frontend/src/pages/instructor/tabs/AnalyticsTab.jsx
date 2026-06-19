import { useState, useMemo } from "react";
import { useQuery } from "@tanstack/react-query";
import {
  ResponsiveContainer,
  LineChart,
  Line,
  XAxis,
  YAxis,
  CartesianGrid,
  Tooltip,
  Legend,
} from "recharts";
import { AlertTriangle } from "lucide-react";
import InsightHeader from "@/components/ui/insight-header";
import ConceptRadarChart from "@/components/concept-radar/ConceptRadarChart";
import SegmentedPicker from "@/components/ui/segmented-picker";
import { KNOWLEDGE_AREA_GROUPS, buildRadarDataForGroup } from "@/data/knowledgeAreaConcepts";
import api from "@/services/api";

const TOOLTIP_STYLE = {
  backgroundColor: "hsl(var(--popover))",
  border: "1px solid hsl(var(--border))",
  borderRadius: "6px",
  fontSize: "12px",
  color: "hsl(var(--popover-foreground))",
};

export default function AnalyticsTab({ sectionId }) {
  const { data: exercises = [], isLoading: exLoading, isError: exError } = useQuery({
    queryKey: ["analytics-exercises", sectionId],
    queryFn: async () => {
      const { data } = await api.get(`/api/sections/${sectionId}/exercises`);
      return data;
    },
    enabled: !!sectionId,
  });

  const { data: longitudinal = [], isLoading: longLoading, isError: longError } = useQuery({
    queryKey: ["analytics-longitudinal", sectionId],
    queryFn: async () => {
      const { data } = await api.get(`/api/analytics/sections/${sectionId}/longitudinal`);
      return data;
    },
    enabled: !!sectionId,
  });

  const [selectedArea, setSelectedArea] = useState('SDF-FPC');

  const { data: radarPayload, isLoading: radarLoading } = useQuery({
    queryKey: ["analytics-class-radar", sectionId],
    queryFn: async () => {
      const { data } = await api.get(`/api/analytics/sections/${sectionId}/class-concept-radar`);
      return data;
    },
    enabled: !!sectionId,
  });

  const concepts = useMemo(() => {
    const conceptMap = {};
    exercises.forEach((ex) => {
      const name = ex.concept_name || "Unknown";
      if (!conceptMap[name]) {
        conceptMap[name] = { name, values: [], ids: new Set() };
      }
      if (ex.avg_cds != null) {
        conceptMap[name].values.push(ex.avg_cds);
        conceptMap[name].ids.add(ex.id);
      }
    });
    return Object.values(conceptMap).map((c) => {
      const avg = c.values.length
        ? c.values.reduce((a, b) => a + b, 0) / c.values.length
        : 0;
      // Convert CDS to mastery: higher mastery = better understanding
      const mastery = Math.round((1 - avg) * 100);
      // Level reflects mastery strength (not difficulty): high mastery = good (green)
      return {
        id: [...c.ids][0] || 0,
        name: c.name,
        value: mastery,
        level: mastery >= 75 ? "high" : mastery >= 50 ? "moderate" : "low",
      };
    });
  }, [exercises]);

  const weakest = useMemo(() => {
    if (!concepts.length) return null;
    return concepts.reduce((min, c) => (c.value < min.value ? c : min), concepts[0]);
  }, [concepts]);

  const trendData = useMemo(() => {
    if (!longitudinal.length) return [];
    const weeklyMap = {};
    longitudinal.forEach((student) => {
      (student.progression || []).forEach((entry) => {
        const date = entry.computed_at ? entry.computed_at.slice(0, 10) : "unknown";
        if (!weeklyMap[date]) weeklyMap[date] = { cds: [], scores: [] };
        if (entry.cds != null) weeklyMap[date].cds.push(entry.cds);
      });
    });
    return Object.entries(weeklyMap)
      .sort(([a], [b]) => a.localeCompare(b))
      .slice(-12)
      .map(([week, vals]) => {
        const avgCds = vals.cds.length
          ? vals.cds.reduce((a, b) => a + b, 0) / vals.cds.length
          : 0;
        return {
          week: week.slice(5),
          cds: +avgCds.toFixed(2),
          mastery: Math.round((1 - avgCds) * 100),
        };
      });
  }, [longitudinal]);

  const radarScores = useMemo(() => {
    if (!radarPayload?.concepts) return [];
    return radarPayload.concepts.map((c) => ({
      concept_name: c.concept_name,
      cds: Number(c.cds) || 0,
      ner: Number(c.ner) || 0,
      nrs: Number(c.nrs) || 0,
      nts: Number(c.nts) || 0,
    }));
  }, [radarPayload]);

  const radarData = useMemo(
    () => buildRadarDataForGroup(radarScores, selectedArea),
    [radarScores, selectedArea]
  );

  const pickerOptions = KNOWLEDGE_AREA_GROUPS.map((g) => ({
    key: g.key,
    label: g.shortLabel,
  }));

  const currentGroup = KNOWLEDGE_AREA_GROUPS.find((g) => g.key === selectedArea);
  const totalConcepts = radarData.length;
  const attemptedConcepts = radarData.filter((d) => d.attempts > 0).length;

  if (exLoading || longLoading) {
    return (
      <div className="rounded-lg border border-border bg-card/50 py-8 px-6 text-center">
        <p className="text-sm font-semibold text-foreground">Loading analytics…</p>
      </div>
    );
  }

  if (exError || longError) {
    return (
      <div className="flex items-center gap-3 rounded-lg border border-destructive/30 bg-destructive/5 px-4 py-3">
        <AlertTriangle className="h-4 w-4 text-destructive shrink-0" />
        <p className="text-sm text-destructive flex-1">Failed to load analytics.</p>
      </div>
    );
  }

  return (
    <div className="space-y-6">
      <InsightHeader
        insight={
          weakest
            ? weakest.value >= 75
              ? `Class shows strong understanding of ${weakest.name}.`
              : `${weakest.name} needs improvement at ${weakest.value}% mastery.`
            : "No analytics data available yet."
        }
      />

      <div className="grid gap-6 md:grid-cols-2">
        <div className="rounded-lg border border-border bg-card shadow-sm">
          <div className="px-5 py-3 border-b border-border">
            <p className="text-[10px] font-semibold uppercase tracking-wider text-muted-foreground">
              Class-Wide
            </p>
            <h3 className="text-sm font-semibold mt-0.5">Concept mastery radar</h3>
          </div>
          <div className="p-5">
            {radarLoading ? (
              <p className="text-sm text-muted-foreground text-center py-8">Loading radar…</p>
            ) : radarData.length > 0 ? (
              <div>
                <div className="flex items-center justify-between mb-3">
                  <SegmentedPicker
                    value={selectedArea}
                    onChange={setSelectedArea}
                    options={pickerOptions}
                    size="sm"
                  />
                  <span className="text-[10px] font-mono uppercase tracking-wider text-muted-foreground/50">
                    {attemptedConcepts}/{totalConcepts} concepts
                  </span>
                </div>
                <p className="text-[10px] text-muted-foreground/50 mb-2 ml-0.5 font-mono tracking-wide">
                  {currentGroup?.label}
                </p>
                <div className="h-72 w-full">
                  <ConceptRadarChart data={radarData} />
                </div>
              </div>
            ) : (
              <p className="text-sm text-muted-foreground text-center py-8">
                No exercise data available yet
              </p>
            )}
          </div>
        </div>

        <div className="rounded-lg border border-border bg-card shadow-sm">
          <div className="px-5 py-3 border-b border-border">
            <p className="text-[10px] font-semibold uppercase tracking-wider text-muted-foreground">
              Details
            </p>
            <h3 className="text-sm font-semibold mt-0.5">
              Longitudinal progress
            </h3>
          </div>
          <div className="p-5">
            {trendData.length > 1 ? (
              <div className="h-64 w-full">
                <ResponsiveContainer width="100%" height="100%">
                  <LineChart
                    data={trendData}
                    margin={{ top: 8, right: 12, bottom: 0, left: -8 }}
                  >
                    <CartesianGrid
                      stroke="hsl(var(--border))"
                      strokeDasharray="3 3"
                      vertical={false}
                    />
                    <XAxis
                      dataKey="week"
                      tick={{ fill: "hsl(var(--muted-foreground))", fontSize: 11 }}
                      axisLine={{ stroke: "hsl(var(--border))" }}
                      tickLine={false}
                    />
                    <YAxis
                      tick={{ fill: "hsl(var(--muted-foreground))", fontSize: 11 }}
                      axisLine={false}
                      tickLine={false}
                      width={40}
                    />
                    <Tooltip contentStyle={TOOLTIP_STYLE} cursor={{ stroke: "hsl(var(--muted))" }} />
                    <Legend
                      wrapperStyle={{ fontSize: "11px", paddingTop: "8px" }}
                      iconType="circle"
                      iconSize={8}
                    />
                    <Line
                      type="monotone"
                      dataKey="cds"
                      name="CDS"
                      stroke="hsl(var(--destructive))"
                      strokeWidth={2}
                      dot={false}
                      isAnimationActive={false}
                    />
                    <Line
                      type="monotone"
                      dataKey="mastery"
                      name="Mastery"
                      stroke="hsl(var(--success))"
                      strokeWidth={2}
                      dot={false}
                      isAnimationActive={false}
                    />
                  </LineChart>
                </ResponsiveContainer>
              </div>
            ) : (
              <p className="text-sm text-muted-foreground text-center py-8">
                Not enough data for trend visualization
              </p>
            )}
          </div>
        </div>
      </div>
    </div>
  );
}
