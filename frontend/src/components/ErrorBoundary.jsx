import { Component } from 'react';

class ErrorBoundary extends Component {
  constructor(props) {
    super(props);
    this.state = { hasError: false };
  }

  static getDerivedStateFromError(error) {
    return { hasError: true };
  }

  componentDidCatch(error, errorInfo) {
    console.error('Error caught by boundary:', error, errorInfo);
  }

  render() {
    if (this.state.hasError) {
      return (
        <div style={{ padding: '20px', color: '#e6edf3', textAlign: 'center' }}>
          <h2>Something went wrong.</h2>
          <p>Check the console for errors.</p>
        </div>
      );
    }

    return this.props.children;
  }
}

export default ErrorBoundary;
