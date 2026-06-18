export default [
  {
    ignores: ['**/node_modules/**', '**/coverage/**', '**/dist/**'],
  },
  {
    rules: {
      'no-unused-vars': 'warn',
      'no-undef': 'error',
      'no-console': 'warn',
      'eqeqeq': 'error',
      'no-throw-literal': 'error',
      'prefer-const': 'error',
      'no-var': 'error',
    },
  },
];
