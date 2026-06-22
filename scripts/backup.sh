#!/bin/bash
set -e

BACKUP_DIR="${BACKUP_DIR:-./backups}"
DB_HOST="${DB_HOST:-localhost}"
DB_PORT="${DB_PORT:-5432}"
DB_NAME="${DB_NAME:-codeinsight}"
DB_USER="${DB_USER:-codeuser}"
DB_PASSWORD="${DB_PASSWORD:-codepassword123}"
RETENTION_DAYS="${RETENTION_DAYS:-7}"
TIMESTAMP=$(date +%Y%m%d_%H%M%S)
BACKUP_FILE="${BACKUP_DIR}/${DB_NAME}_${TIMESTAMP}.sql.gz"

cleanup() {
  echo "Backup process interrupted or failed. Cleaning up..."
  rm -f "$BACKUP_FILE"
  exit 1
}
trap cleanup ERR INT TERM

mkdir -p "$BACKUP_DIR"

echo "Starting backup of ${DB_NAME} at ${TIMESTAMP}"
PGPASSWORD="$DB_PASSWORD" pg_dump \
  -h "$DB_HOST" \
  -p "$DB_PORT" \
  -U "$DB_USER" \
  -d "$DB_NAME" \
  --no-owner \
  --no-acl \
  --format=custom \
  | gzip > "$BACKUP_FILE"

echo "Backup saved to ${BACKUP_FILE}"

find "$BACKUP_DIR" -name "${DB_NAME}_*.sql.gz" -type f -mtime +${RETENTION_DAYS} -delete 2>/dev/null
echo "Cleaned up backups older than ${RETENTION_DAYS} days"

echo "Backup complete"
