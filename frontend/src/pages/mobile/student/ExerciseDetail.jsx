import { useParams } from 'react-router-dom';
import { useState } from 'react';
import { getConfig } from '../../../config/useLayoutConfig.js';
import { useFetch } from '../MobileScreen.jsx';
import { CodePreviewSurface } from '../../../components/mobile/CodePreviewSurface.jsx';
import { TestResultList } from '../../../components/mobile/TestResultList.jsx';
import { OpenFullEditorHint } from '../../../components/mobile/OpenFullEditorHint.jsx';

export default function ExerciseDetail() {
  const { id } = useParams();
  const screen = getConfig('student', 'mobile').screens['/student/exercises/:id'];
  const { data } = useFetch(`/api/exercises/${id}`);
  const [results, setResults] = useState(null);

  return (
    <main className="mobile-content">
      <CodePreviewSurface
        data={data}
        onRun={async () => { const r = await fetch(`/api/exercises/${id}/run`, { method: 'POST' }); setResults(await r.json()); }}
        onSubmit={async () => { const r = await fetch(`/api/submissions`, { method: 'POST', body: JSON.stringify({ exerciseId: id, code: data?.code }) }); setResults(await r.json()); }}
      />
      <TestResultList data={results} />
      <OpenFullEditorHint />
    </main>
  );
}
