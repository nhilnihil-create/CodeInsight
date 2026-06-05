import { clsx } from "clsx";
import { twMerge } from "tailwind-merge";

/**
 * Combine class names with Tailwind merge.
 * Standard shadcn/ui helper used by every component.
 */
export function cn(...inputs) {
  return twMerge(clsx(inputs));
}
