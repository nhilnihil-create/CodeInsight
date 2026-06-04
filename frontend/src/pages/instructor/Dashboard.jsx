import { Card, CardContent, CardHeader, CardTitle } from "@/components/ui/card";
import { Users, Code2, AlertTriangle, Activity } from "lucide-react";
import { Link } from "react-router-dom";
import ClassMisconceptionReport from "@/components/analytics/ClassMisconceptionReport";
import IntegrityMonitoringBanner from "@/components/analytics/IntegrityMonitoringBanner";

export default function InstructorDashboard() {
  return (
    <div className="space-y-6">
      <div>
        <h1 className="text-3xl font-bold tracking-tight">Instructor Dashboard</h1>
        <p className="text-muted-foreground">Class overview and active alerts.</p>
      </div>

      <div className="grid gap-6 md:grid-cols-2 lg:grid-cols-4">
        <Card>
          <CardHeader className="flex flex-row items-center justify-between space-y-0 pb-2">
            <CardTitle className="text-sm font-medium">Total Students</CardTitle>
            <Users className="w-4 h-4 text-muted-foreground" />
          </CardHeader>
          <CardContent>
            <div className="text-2xl font-bold">142</div>
          </CardContent>
        </Card>
        <Card>
          <CardHeader className="flex flex-row items-center justify-between space-y-0 pb-2">
            <CardTitle className="text-sm font-medium">Active Exercises</CardTitle>
            <Code2 className="w-4 h-4 text-muted-foreground" />
          </CardHeader>
          <CardContent>
            <div className="text-2xl font-bold">8</div>
          </CardContent>
        </Card>
        <Card className="bg-destructive/5 border-destructive/20">
          <CardHeader className="flex flex-row items-center justify-between space-y-0 pb-2">
            <CardTitle className="text-sm font-medium text-destructive">Critical Alerts</CardTitle>
            <AlertTriangle className="w-4 h-4 text-destructive" />
          </CardHeader>
          <CardContent>
            <div className="text-2xl font-bold text-destructive">12</div>
            <Link to="/instructor/warnings" className="text-xs text-destructive hover:underline mt-1 inline-block">View all warnings</Link>
          </CardContent>
        </Card>
        <Card>
          <CardHeader className="flex flex-row items-center justify-between space-y-0 pb-2">
            <CardTitle className="text-sm font-medium">Avg Class CDS</CardTitle>
            <Activity className="w-4 h-4 text-muted-foreground" />
          </CardHeader>
          <CardContent>
            <div className="text-2xl font-bold">42.5</div>
            <p className="text-xs text-muted-foreground">Medium Difficulty</p>
          </CardContent>
        </Card>
      </div>

      <div className="grid gap-6 md:grid-cols-2 lg:grid-cols-3">
        <Card className="md:col-span-2">
          <CardHeader>
            <CardTitle>Class Concept Averages</CardTitle>
          </CardHeader>
          <CardContent>
            <div className="space-y-4">
              {[
                { name: "Datatypes", cds: 22 },
                { name: "Variables", cds: 28 },
                { name: "Conditionals", cds: 45 },
                { name: "Loops", cds: 68 },
                { name: "Functions", cds: 55 },
                { name: "Arrays", cds: 72 },
                { name: "OOP", cds: 30 }
              ].map((concept) => (
                <div key={concept.name} className="flex items-center">
                  <div className="w-24 text-sm font-medium">{concept.name}</div>
                  <div className="flex-1 flex items-center gap-2">
                    <div className="w-full bg-muted rounded-full h-2">
                      <div
                        className={`h-2 rounded-full ${concept.cds > 75 ? 'bg-destructive' : concept.cds > 50 ? 'bg-orange-500' : concept.cds > 25 ? 'bg-blue-500' : 'bg-green-500'}`}
                        style={{ width: `${concept.cds}%` }}
                      />
                    </div>
                    <div className="w-8 text-right text-xs text-muted-foreground font-mono">{concept.cds}</div>
                  </div>
                </div>
              ))}
            </div>
          </CardContent>
        </Card>

        <Card>
          <CardHeader>
            <CardTitle>Recent Activity</CardTitle>
          </CardHeader>
          <CardContent>
            <div className="space-y-4">
              {[
                { user: "Alex Santos", action: "Triggered alert on Loops", time: "10m ago" },
                { user: "Maria Garcia", action: "Passed Array Reversal", time: "25m ago" },
                { user: "John Doe", action: "Integrity flag on Basic Loops", time: "1h ago" },
                { user: "System", action: "Generated weekly report", time: "2h ago" },
              ].map((item, i) => (
                <div key={i} className="flex flex-col gap-1 pb-3 border-b last:border-0 last:pb-0">
                  <div className="text-sm font-medium">{item.user}</div>
                  <div className="text-xs text-muted-foreground">{item.action}</div>
                  <div className="text-[10px] text-muted-foreground/70">{item.time}</div>
                </div>
              ))}
            </div>
          </CardContent>
        </Card>
      </div>

      <Card>
        <CardHeader>
          <CardTitle>Class Misconceptions</CardTitle>
        </CardHeader>
        <CardContent>
          <ClassMisconceptionReport embedded />
        </CardContent>
      </Card>

      <IntegrityMonitoringBanner />
    </div>
  );
}
