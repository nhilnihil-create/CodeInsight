import Sidebar from './Sidebar';
import { useSidebar } from '../context/SidebarContext';

export default function Layout({ children }) {
  const { isOpen } = useSidebar();

  return (
    <>
      <Sidebar />
      <main style={{
        marginLeft: isOpen ? '120px' : '70px',
        height: '100vh',
        overflow: 'auto',
        background: '#0d1117',
        transition: 'margin-left 0.3s ease'
      }}>
        {children}
      </main>
    </>
  );
}
