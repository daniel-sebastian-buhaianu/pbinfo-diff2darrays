#include <iostream>
using namespace std;
int** citesteMatrice(int n);
int** construiesteMatrice(int** a, int n);
int** sumaPartiala(int** a, int n);
int main()
{
  int n; cin >> n;
  int** a = citesteMatrice(n);
  int** b = construiesteMatrice(a, n);
  int q; cin >> q;
  for (int i = 0; i < q; i++)
  {
    int l1, c1, l2, c2, v;
    cin >> l1 >> c1 >> l2 >> c2 >> v;
    l1--, c1--, l2--, c2--; // retin indicii de la 0
    b[l1][c1] += v;
    b[l2+1][c2+1] += v;
    b[l1][c2+1] -= v;
    b[l2+1][c1] -= v;
  }
  a = sumaPartiala(b, n);
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
      cout << a[i][j] << ' ';
    cout << '\n';
  }
  return 0;
}
int** sumaPartiala(int** a, int n)
{
  int** sp = new int*[n];
  for (int i = 0; i < n; i++) sp[i] = new int[n];
  sp[0][0] = a[0][0];
  for (int i = 1; i < n; i++)
  {
    sp[0][i] = sp[0][i-1] + a[0][i];
    sp[i][0] = sp[i-1][0] + a[i][0];
  }
  for (int i = 1; i < n; i++)
    for (int j = 1; j < n; j++)
      sp[i][j] = a[i][j] + sp[i-1][j] + sp[i][j-1] - sp[i-1][j-1];
  return sp;
}
int** construiesteMatrice(int** a, int n)
{
  // a = matrice de sume partiale pentru b
  int** b = new int*[n+1];
  for (int i = 0; i < n+1; i++) b[i] = new int[n+1];
  b[0][0] = a[0][0];
  b[0][n] = b[n][0] = 0;
  for (int i = 1; i < n; i++)
  {
    b[0][i] = a[0][i] - a[0][i-1];
    b[i][0] = a[i][0] - a[i-1][0];
    b[i][n] = b[n][i] = 0;
  }
  for (int i = 1; i < n; i++)
    for (int j = 1; j < n; j++)
      b[i][j] = a[i][j] - a[i-1][j] - a[i][j-1] + a[i-1][j-1];
  return b;
} 
int** citesteMatrice(int n)
{
  int** a = new int*[n];
  for (int i = 0; i < n; i++)
  {
    a[i] = new int[n];
    for (int j = 0; j < n; j++) cin >> a[i][j];
  }
  return a;
}
