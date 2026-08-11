import api from '@/services/api';

/**
 * Canonical export API client.
 *
 * GET /api/export/:domain/:sectionId?format=csv|xlsx|json[&studentId=]
 * Joi-validated and ownership-guarded on the backend; the server sends the
 * download back as a blob with an RFC 5987 Content-Disposition header.
 */

export function buildExportUrl(domain, sectionId, { format = 'csv', studentId } = {}) {
  let url = `/api/export/${domain}/${sectionId}?format=${format}`;
  // eslint-disable-next-line eqeqeq -- intentional nullish guard (null or undefined)
  if (studentId != null) {
    url += `&studentId=${studentId}`;
  }
  return url;
}

/**
 * Extract the filename from a Content-Disposition header.
 * Handles the plain `filename="..."` form and the RFC 5987
 * `filename*=UTF-8''<percent-encoded>` form (preferred when both exist).
 */
function parseContentDisposition(header) {
  if (!header) return null;

  const star = header.match(/filename\*=UTF-8''([^;]+)/i);
  if (star) {
    try {
      return decodeURIComponent(star[1].trim());
    } catch {
      // fall through to the plain form
    }
  }

  const plain = header.match(/filename="?([^";]+)"?/i);
  if (plain) return plain[1].trim();
  return null;
}

export async function fetchExportBlob(domain, sectionId, { format = 'csv', studentId } = {}) {
  const url = buildExportUrl(domain, sectionId, { format, studentId });
  const res = await api.get(url, { responseType: 'blob' });
  const fileName =
    parseContentDisposition(res.headers?.['content-disposition']) || `export.${format}`;
  return { blob: res.data, fileName };
}

export function triggerDownload(blob, fileName) {
  const url = URL.createObjectURL(blob);
  const a = document.createElement('a');
  a.href = url;
  a.download = fileName;
  document.body.appendChild(a);
  a.click();
  a.remove();
  URL.revokeObjectURL(url);
}
