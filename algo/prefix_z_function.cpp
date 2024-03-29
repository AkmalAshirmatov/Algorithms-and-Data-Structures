vector<int> z_function(string s) {
  int n = s.size();
  vector<int> z(n);
  for (int i = 1, l = 0, r = 0; r < n; i++) {
    if (i <= r)
      z[i] = min(r-i+1, z[i-l]);
    while (i+z[i] < n && s[z[i]] == s[i+z[i]])
      z[i]++;
    if (i+z[i]-1 > r)
      l = i, r = i+z[i]-1;
  }
  return z;
}

vector<int> prefix_function(string s) {
  int n = s.size();
  vector<int> pi(n);
  for (int i = 1; i < n; i++) {
    int j = pi[i-1];
    while (j > 0 && s[i] != s[j])
      j = pi[j-1];
    if (s[i] == s[j]) j++;
    pi[i] = j;
  }
  return pi;
}
