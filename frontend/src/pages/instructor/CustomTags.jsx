import { useState, useEffect, useCallback } from 'react';
import { useParams, Link } from 'react-router-dom';
import {
  Plus, ArrowLeft, Trash2, Eye, EyeOff, Save, X,
  Tags, Loader2, AlertTriangle, Check, ChevronDown,
} from 'lucide-react';
import { Button } from '@/components/ui/button';
import { Input } from '@/components/ui/input';
import { Badge } from '@/components/ui/badge';
import {
  Dialog, DialogContent, DialogHeader, DialogTitle, DialogFooter,
} from '@/components/ui/dialog';
import api from '@/services/api';
import { cn } from '@/lib/utils';

const COLOR_THEMES = [
  { value: 'slate', label: 'Slate', class: 'bg-slate-500/20 text-slate-400 border-slate-500/30' },
  { value: 'emerald', label: 'Emerald', class: 'bg-emerald-500/20 text-emerald-400 border-emerald-500/30' },
  { value: 'amber', label: 'Amber', class: 'bg-amber-500/20 text-amber-400 border-amber-500/30' },
  { value: 'rose', label: 'Rose', class: 'bg-rose-500/20 text-rose-400 border-rose-500/30' },
  { value: 'violet', label: 'Violet', class: 'bg-violet-500/20 text-violet-400 border-violet-500/30' },
  { value: 'cyan', label: 'Cyan', class: 'bg-cyan-500/20 text-cyan-400 border-cyan-500/30' },
];

export default function InstructorCustomTags() {
  const { sectionId } = useParams();
  const [tags, setTags] = useState([]);
  const [exercises, setExercises] = useState([]);
  const [loading, setLoading] = useState(true);
  const [error, setError] = useState(null);
  const [expandedTag, setExpandedTag] = useState(null);
  const [mappedIds, setMappedIds] = useState({});

  const [createOpen, setCreateOpen] = useState(false);
  const [newName, setNewName] = useState('');
  const [newColor, setNewColor] = useState('slate');
  const [creating, setCreating] = useState(false);

  const [editName, setEditName] = useState('');
  const [editingTagId, setEditingTagId] = useState(null);
  const [savingEdit, setSavingEdit] = useState(false);

  const fetchTags = useCallback(async () => {
    try {
      const { data } = await api.get(`/api/custom-tags?sectionId=${sectionId}`);
      setTags(data);
    } catch (err) {
      setError(err.response?.data?.error || 'Failed to load tags');
    }
  }, [sectionId]);

  const fetchExercises = useCallback(async () => {
    try {
      const { data } = await api.get(`/api/sections/${sectionId}/exercises`);
      setExercises(data);
    } catch (err) {
      // non-critical
    }
  }, [sectionId]);

  const loadData = useCallback(async () => {
    setLoading(true);
    setError(null);
    await Promise.all([fetchTags(), fetchExercises()]);
    setLoading(false);
  }, [fetchTags, fetchExercises]);

  useEffect(() => { loadData(); }, [loadData]);

  const handleCreate = async () => {
    if (!newName.trim()) return;
    setCreating(true);
    try {
      await api.post('/api/custom-tags', { tag_name: newName.trim(), color_theme: newColor });
      setCreateOpen(false);
      setNewName('');
      setNewColor('slate');
      await fetchTags();
    } catch (err) {
      setError(err.response?.data?.error || 'Failed to create tag');
    } finally {
      setCreating(false);
    }
  };

  const handleToggleActive = async (tag) => {
    try {
      await api.put(`/api/custom-tags/${tag.id}`, { is_active_column: !tag.is_active_column });
      await fetchTags();
    } catch (err) {
      setError(err.response?.data?.error || 'Failed to update tag');
    }
  };

  const handleDelete = async (tagId) => {
    try {
      await api.delete(`/api/custom-tags/${tagId}`);
      setExpandedTag((prev) => prev === tagId ? null : prev);
      await fetchTags();
    } catch (err) {
      setError(err.response?.data?.error || 'Failed to delete tag');
    }
  };

  const handleStartEdit = (tag) => {
    setEditingTagId(tag.id);
    setEditName(tag.tag_name);
  };

  const handleSaveEdit = async () => {
    if (!editName.trim()) return;
    setSavingEdit(true);
    try {
      await api.put(`/api/custom-tags/${editingTagId}`, { tag_name: editName.trim() });
      setEditingTagId(null);
      await fetchTags();
    } catch (err) {
      setError(err.response?.data?.error || 'Failed to rename tag');
    } finally {
      setSavingEdit(false);
    }
  };

  const toggleTagExpand = async (tagId) => {
    if (expandedTag === tagId) {
      setExpandedTag(null);
      return;
    }
    setExpandedTag(tagId);

    // Fetch mapped exercises for this tag
    try {
      const { data: mapped } = await api.get(`/api/custom-tags/${tagId}/exercises?sectionId=${sectionId}`);
      const ids = {};
      for (const ex of mapped) ids[ex.id] = true;
      setMappedIds((prev) => ({ ...prev, [tagId]: ids }));
    } catch (err) {
      // silent
    }
  };

  const handleMapToggle = async (tagId, exerciseId, currentlyMapped) => {
    if (currentlyMapped) {
      await api.delete(`/api/custom-tags/${tagId}/exercises/${exerciseId}`);
    } else {
      await api.post(`/api/custom-tags/${tagId}/exercises`, { exercise_ids: [exerciseId] });
    }
    setMappedIds((prev) => {
      const next = { ...prev };
      if (!next[tagId]) next[tagId] = {};
      next[tagId] = { ...next[tagId], [exerciseId]: !currentlyMapped };
      return next;
    });
    await fetchTags();
  };

  if (loading) {
    return (
      <div className="flex items-center justify-center min-h-[400px]">
        <div className="flex items-center gap-3 text-muted-foreground">
          <Loader2 className="h-5 w-5 animate-spin" />
          <span className="text-sm">Loading custom tags...</span>
        </div>
      </div>
    );
  }

  return (
    <div className="w-full space-y-6">
      <div className="flex items-center justify-between">
        <div className="flex items-center gap-3">
          <Link to={`/instructor/sections/${sectionId}`}>
            <Button variant="ghost" size="icon" className="h-8 w-8">
              <ArrowLeft className="h-4 w-4" />
            </Button>
          </Link>
          <div>
            <h1 className="text-xl font-semibold text-foreground tracking-wide">
              Custom Tags
            </h1>
            <p className="text-xs text-muted-foreground mt-0.5">
              Create pedagogical concept tags and map exercises to build custom heatmap columns.
            </p>
          </div>
        </div>
        <Button onClick={() => setCreateOpen(true)} className="gap-2">
          <Plus className="h-4 w-4" />
          Create Tag
        </Button>
      </div>

      {error && (
        <div className="flex items-center gap-3 rounded-lg border border-destructive/30 bg-destructive/5 px-4 py-3">
          <AlertTriangle className="h-4 w-4 text-destructive shrink-0" />
          <p className="text-sm text-destructive flex-1">{error}</p>
          <Button variant="outline" size="sm" onClick={() => setError(null)}>
            <X className="h-3.5 w-3.5" />
          </Button>
        </div>
      )}

      {tags.length === 0 ? (
        <div className="flex flex-col items-center justify-center py-20 rounded-xl border border-dashed border-border bg-card/30">
          <Tags className="h-10 w-10 text-muted-foreground/40 mb-4" />
          <p className="text-sm font-medium text-muted-foreground mb-1">
            No custom tags yet
          </p>
          <p className="text-xs text-muted-foreground/60 mb-4">
            Create your first tag to start organizing exercises by pedagogical concept.
          </p>
          <Button onClick={() => setCreateOpen(true)} size="sm" className="gap-2">
            <Plus className="h-4 w-4" />
            Create Tag
          </Button>
        </div>
      ) : (
        <div className="grid gap-4">
          {tags.map((tag) => {
            const isExpanded = expandedTag === tag.id;
            return (
              <div
                key={tag.id}
                className="rounded-xl border border-border bg-card shadow-sm overflow-hidden"
              >
                <div className="flex items-center justify-between p-4">
                  <div className="flex items-center gap-3 flex-1 min-w-0">
                    {editingTagId === tag.id ? (
                      <div className="flex items-center gap-2">
                        <Input
                          value={editName}
                          onChange={(e) => setEditName(e.target.value)}
                          className="h-8 w-64 text-sm"
                          autoFocus
                        />
                        <Button size="icon" variant="ghost" className="h-8 w-8" onClick={handleSaveEdit} disabled={savingEdit}>
                          {savingEdit ? <Loader2 className="h-3.5 w-3.5 animate-spin" /> : <Check className="h-3.5 w-3.5" />}
                        </Button>
                        <Button size="icon" variant="ghost" className="h-8 w-8" onClick={() => setEditingTagId(null)}>
                          <X className="h-3.5 w-3.5" />
                        </Button>
                      </div>
                    ) : (
                      <div className="flex items-center gap-2 min-w-0">
                        <span className="font-medium text-foreground truncate">{tag.tag_name}</span>
                        <span className={cn(
                          'px-2 py-0.5 rounded text-[10px] font-medium border',
                          COLOR_THEMES.find((c) => c.value === tag.color_theme)?.class || COLOR_THEMES[0].class,
                        )}>
                          {tag.color_theme}
                        </span>
                      </div>
                    )}
                    <span className="text-xs text-muted-foreground">
                      {tag.exercise_count} exercise{tag.exercise_count !== 1 ? 's' : ''}
                    </span>
                    {!tag.is_active_column && (
                      <Badge variant="outline" className="text-[10px] text-muted-foreground border-dashed">
                        hidden
                      </Badge>
                    )}
                  </div>
                  <div className="flex items-center gap-1">
                    <Button size="icon" variant="ghost" className="h-8 w-8" onClick={() => handleToggleActive(tag)} title={tag.is_active_column ? 'Hide column' : 'Show column'}>
                      {tag.is_active_column ? <Eye className="h-3.5 w-3.5" /> : <EyeOff className="h-3.5 w-3.5 text-muted-foreground" />}
                    </Button>
                    {editingTagId !== tag.id && (
                      <Button size="icon" variant="ghost" className="h-8 w-8" onClick={() => handleStartEdit(tag)} title="Rename">
                        <Save className="h-3.5 w-3.5" />
                      </Button>
                    )}
                    <Button size="icon" variant="ghost" className="h-8 w-8 text-destructive hover:text-destructive" onClick={() => handleDelete(tag.id)} title="Delete">
                      <Trash2 className="h-3.5 w-3.5" />
                    </Button>
                    <Button size="icon" variant="ghost" className="h-8 w-8" onClick={() => toggleTagExpand(tag.id)} title="Map exercises">
                      <ChevronDown className={cn('h-4 w-4 transition-transform', isExpanded && 'rotate-180')} />
                    </Button>
                  </div>
                </div>

                {isExpanded && (
                  <div className="border-t border-border px-4 py-3 bg-muted/20">
                    <p className="text-xs font-medium text-muted-foreground mb-3">
                      Map exercises from this section to "{tag.tag_name}":
                    </p>
                    {exercises.length === 0 ? (
                      <p className="text-xs text-muted-foreground/60 py-4 text-center">
                        No exercises in this section yet.
                      </p>
                    ) : (
                      <div className="grid gap-1.5 max-h-64 overflow-y-auto">
                        {exercises.map((ex) => {
                          const isMapped = mappedIds[tag.id]?.[ex.id] || false;
                          return (
                            <label
                              key={ex.id}
                              className={cn(
                                'flex items-center gap-3 px-3 py-2 rounded-lg text-sm cursor-pointer transition-colors',
                                isMapped ? 'bg-primary/10 border border-primary/20' : 'hover:bg-muted/40 border border-transparent',
                              )}
                            >
                              <input
                                type="checkbox"
                                checked={isMapped}
                                onChange={() => handleMapToggle(tag.id, ex.id, isMapped)}
                                className="accent-primary h-4 w-4 rounded border-border"
                              />
                              <span className="flex-1 min-w-0 truncate text-foreground/90">{ex.title}</span>
                              {isMapped && <Check className="h-3.5 w-3.5 text-primary shrink-0" />}
                            </label>
                          );
                        })}
                      </div>
                    )}
                  </div>
                )}
              </div>
            );
          })}
        </div>
      )}

      {/* Create Dialog */}
      <Dialog open={createOpen} onOpenChange={setCreateOpen}>
        <DialogContent>
          <DialogHeader>
            <DialogTitle>Create Custom Tag</DialogTitle>
          </DialogHeader>
          <div className="space-y-4 py-2">
            <div>
              <label className="text-xs font-medium text-muted-foreground mb-1.5 block">
                Tag Name
              </label>
              <Input
                value={newName}
                onChange={(e) => setNewName(e.target.value)}
                placeholder="e.g. Week 3: Nested Loops"
                autoFocus
              />
            </div>
            <div>
              <label className="text-xs font-medium text-muted-foreground mb-1.5 block">
                Color Theme
              </label>
              <div className="flex flex-wrap gap-2">
                {COLOR_THEMES.map((theme) => (
                  <button
                    key={theme.value}
                    onClick={() => setNewColor(theme.value)}
                    className={cn(
                      'px-3 py-1.5 rounded-lg text-xs font-medium border transition-all',
                      theme.class,
                      newColor === theme.value && 'ring-2 ring-ring ring-offset-2 ring-offset-background',
                    )}
                  >
                    {theme.label}
                  </button>
                ))}
              </div>
            </div>
          </div>
          <DialogFooter>
            <Button variant="outline" onClick={() => setCreateOpen(false)}>Cancel</Button>
            <Button onClick={handleCreate} disabled={!newName.trim() || creating}>
              {creating ? <Loader2 className="h-4 w-4 animate-spin mr-1" /> : null}
              Create
            </Button>
          </DialogFooter>
        </DialogContent>
      </Dialog>
    </div>
  );
}
