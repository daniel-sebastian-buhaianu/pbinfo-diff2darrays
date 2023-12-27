#include <iostream>
using namespace std;
void update(int**, int, int, int, int, int, int);
int main()
{
  int n; cin >> n;
  int** a = new int*[n];
  for (int i = 0; i < n; i++)
  {
    a[i] = new int[n];
    for (int j = 0; j < n; j++)
      cin >> a[i][j];
  }
  int q; cin >> q;
  for (int i = 0; i < q; i++)
  {
    int l1, c1, l2, c2, v;
    cin >> l1 >> c1 >> l2 >> c2 >> v;
    l1--, c1--, l2--, c2--;
    update(a, n, l1, c1, l2, c2, v);
  }
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
      cout << a[i][j] << ' ';
    cout << '\n';
  }
  return 0;
}
void update(int** a, int n, int l1, int c1, int l2, int c2, int v)
{
  for (int i = l1; i <= l2; i++)
    for (int j = c1; j <= c2; j++)
      a[i][j] += v;
}
