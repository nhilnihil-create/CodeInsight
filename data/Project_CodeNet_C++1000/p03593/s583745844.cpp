#include <cstdio>
#include <queue>

int count[26];

int main()
{
  int h, w;
  char s[101];
  scanf("%d%d", &h, &w);
  for (int i = 0; i < h; ++i)
  {
    scanf("%s", s);
    for (int j = 0; j < w; ++j)
    {
      count[s[j] - 'a']++;
    }
  }
  std::priority_queue<int> q;
  for (int i = 0; i < 26; ++i)
  {
    if (count[i] == 0) continue;
    q.emplace(count[i]);
  }
  int m4 = (h / 2) * (w / 2);
  int m2 = (h & 1) * (w / 2) + (w & 1) * (h / 2);
  int m1 = h & w & 1;
  while (m4 > 0)
  {
    int a = q.top(); q.pop();
    if (a < 4)
    {
      puts("No");
      return 0;
    }
    q.emplace(a - 4);
    m4--;
  }
  while (m2 > 0)
  {
    int a = q.top(); q.pop();
    if (a < 2)
    {
      puts("No");
      return 0;
    }
    q.emplace(a - 2);
    m2--;
  }
  puts("Yes");
  return 0;
}