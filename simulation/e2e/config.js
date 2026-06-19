const BASE_URL = 'http://localhost:5173';
const BACKEND_URL = 'http://localhost:5000';
const SECTION_TITLE = 'E2E Test Section';
const EXERCISE_TITLE = 'Sum 1..N';
const DB_CONFIG = {
  host: 'localhost', port: 5432,
  database: 'codeinsight',
  user: 'codeuser',
  password: 'codepassword123',
};
const ARCHETYPES = {
  HIGH: 'high', AVERAGE: 'average', STRUGGLING: 'struggling',
  HARDCODER: 'hardcoder', BLANK: 'blank',
};
const CONCURRENCY = 3;
const STUDENT_COUNT = 21;
const INSTRUCTOR = { email: 'instructor@psu.edu', password: 'password123' };
const STUDENT_PASSWORD = 'test1234';
module.exports = { BASE_URL, BACKEND_URL, SECTION_TITLE, EXERCISE_TITLE,
  DB_CONFIG, ARCHETYPES, CONCURRENCY, STUDENT_COUNT, INSTRUCTOR, STUDENT_PASSWORD };
