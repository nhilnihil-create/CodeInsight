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
import InsightHeader from "@/components/ui/insight-header";
import ConceptMasteryBarSet from "@/components/ui/concept-mastery-bar-set";

const CONCEPTS = [
  { id: 1, name: "Recursion",         value: 32, level: "low" },
  { id: 2, name: "Loops",             value: 38, level: "low" },
  { id: 3, name: "Arrays",            value: 56, level: "moderate" },
  { id: 4, name: "Strings",           value: 62, level: "moderate" },
  { id: 5, name: "Hashing",           value: 71, level: "high" },
  { id: 6, name: "Sorting",           value: 76, level: "high" },
  { id: 7, name: "Dynamic Programming", value: 81, level: "high" },
];

const TREND = [
  { week: "W1", cds: 0.55, mastery: 52, engagement: 70 },
  { week: "W2", cds: 0.60, mastery: 55, engagement: 72 },
  { week: "W3", cds: 0.65, mastery: 57, engagement: 68 },
  { week: "W4", cds: 0.68, mastery: 60, engagement: 74 },
  { week: "W5", cds: 0.71, mastery: 62, engagement: 71 },
  { week: "W6", cds: 0.74, mastery: 64, engagement: 76 },
];

const TOOLTIP_STYLE = {
  backgroundColor: "hsl(var(--popover))",
  border: "1px solid hsl(var(--border))",
  borderRadius: "6px",
  fontSize: "12px",
  color: "hsl(var(--popover-foreground))",
};

export default function AnalyticsTab() {
  return (
    <div className="space-y-6">
      <InsightHeader
        insight="Recursion and loops are the weakest concepts this week."
      />

      <div className="grid gap-6 md:grid-cols-2">
        <div className="rounded-lg border border-border bg-card shadow-sm">
          <div className="px-5 py-3 border-b border-border">
            <p className="text-[10px] font-semibold uppercase tracking-wider text-muted-foreground">
              Details
            </p>
            <h3 className="text-sm font-semibold mt-0.5">Concept mastery</h3>
          </div>
          <div className="p-5">
            <ConceptMasteryBarSet concepts={CONCEPTS} />
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
            <div className="h-64 w-full">
              <ResponsiveContainer width="100%" height="100%">
                <LineChart
                  data={TREND}
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
                  <Line
                    type="monotone"
                    dataKey="engagement"
                    name="Engagement"
                    stroke="hsl(var(--info))"
                    strokeWidth={2}
                    dot={false}
                    isAnimationActive={false}
                  />
                </LineChart>
              </ResponsiveContainer>
            </div>
          </div>
        </div>
      </div>
    </div>
  );
}
