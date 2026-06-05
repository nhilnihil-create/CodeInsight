import { useState, useEffect } from 'react';
import { Link } from 'react-router-dom';
import { Plus, Download, Upload, ChevronRight } from 'lucide-react';
import api from '../../services/api';
import { Card, CardContent, CardHeader, CardTitle } from '@/components/ui/card';
import { Button } from '@/components/ui/button';
import { Badge } from '@/components/ui/badge';
import { cn } from '@/lib/utils';

const POLICY_COLORS = {
  code: 'text-[#22C55E] bg-[#22C55E]/10 border-[#22C55E]/30',
  request: 'text-[#FACC15] bg-[#FACC15]/10 border-[#FACC15]/30',
  closed: 'text-[#EF4444] bg-[#EF4444]/10 border-[#EF4444]/30',
};

export default function AdminSections() {
  const [sections, setSections] = useState([]);
  const [loading, setLoading] = useState(true);

  useEffect(() => {
    const load = async () => {
      try {
        const res = await api.get('/api/admin/sections').catch(() => null);
        setSections(res?.data || [
          { id: 1, name: 'BSIT-1A · Morning', course_code: 'CS101', instructor_name: 'Dr. Reyes', student_count: 47, join_policy: 'code', status: 'active', semester: 'Sem 1' },
          { id: 2, name: 'BSIT-1B · Afternoon', course_code: 'CS101', instructor_name: 'Dr. Reyes', student_count: 52, join_policy: 'request', status: 'active', semester: 'Sem 1' },
          { id: 3, name: 'BSCS-1A · Morning', course_code: 'CS102', instructor_name: 'Prof. Garcia', student_count: 38, join_policy: 'code', status: 'active', semester: 'Sem 1' },
        ]);
      } catch (err) {
        console.error(err);
      } finally {
        setLoading(false);
      }
    };
    load();
  }, []);

  if (loading) return <div className="text-muted-foreground">Loading sections...</div>;

  return (
    <div className="space-y-4">
      <div className="flex items-center justify-between">
        <p className="text-sm text-muted-foreground">{sections.length} sections · {sections.reduce((s, sec) => s + (sec.student_count || 0), 0)} total students</p>
        <div className="flex gap-2">
          <Button variant="outline" size="sm"><Download className="mr-1 h-3.5 w-3.5" /> Export CSV</Button>
          <Button size="sm"><Upload className="mr-1 h-3.5 w-3.5" /> Bulk Import</Button>
        </div>
      </div>
      <Card>
        <div className="overflow-x-auto">
          <table className="w-full border-collapse text-xs">
            <thead className="bg-muted/30">
              <tr>
                <th className="border-b border-border px-3 py-2.5 text-left text-[9px] font-bold uppercase tracking-wider text-muted-foreground">Section</th>
                <th className="border-b border-border px-3 py-2.5 text-left text-[9px] font-bold uppercase tracking-wider text-muted-foreground">Course</th>
                <th className="border-b border-border px-3 py-2.5 text-left text-[9px] font-bold uppercase tracking-wider text-muted-foreground">Instructor</th>
                <th className="border-b border-border px-3 py-2.5 text-center text-[9px] font-bold uppercase tracking-wider text-muted-foreground">Students</th>
                <th className="border-b border-border px-3 py-2.5 text-center text-[9px] font-bold uppercase tracking-wider text-muted-foreground">Policy</th>
                <th className="border-b border-border px-3 py-2.5 text-center text-[9px] font-bold uppercase tracking-wider text-muted-foreground">Status</th>
              </tr>
            </thead>
            <tbody>
              {sections.map(sec => (
                <tr key={sec.id} className="border-b border-border/60 last:border-0 hover:bg-muted/20">
                  <td className="px-3 py-2.5">
                    <Link to={`/instructor/sections/${sec.id}`} className="font-semibold text-foreground hover:text-primary">{sec.name}</Link>
                    <div className="text-[9px] text-muted-foreground">{sec.semester || 'Sem 1'}</div>
                  </td>
                  <td className="px-3 py-2.5 font-mono text-muted-foreground">{sec.course_code}</td>
                  <td className="px-3 py-2.5 text-muted-foreground">{sec.instructor_name || '—'}</td>
                  <td className="px-3 py-2.5 text-center font-mono font-bold text-foreground">{sec.student_count || 0}</td>
                  <td className="px-3 py-2.5 text-center">
                    <Badge variant="outline" className={cn('text-[9px] px-1.5 py-0', POLICY_COLORS[sec.join_policy] || '')}>
                      {sec.join_policy || 'code'}
                    </Badge>
                  </td>
                  <td className="px-3 py-2.5 text-center">
                    <Badge variant="outline" className={cn('text-[9px]', sec.status === 'active' ? 'text-emerald-500 border-emerald-500/30' : 'text-muted-foreground')}>
                      {sec.status}
                    </Badge>
                  </td>
                </tr>
              ))}
            </tbody>
          </table>
        </div>
      </Card>
    </div>
  );
}
