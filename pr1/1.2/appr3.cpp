int n;
cin >> n;
vector<int> a(n+1), freq(n+1, 0);

for (int i = 1; i <= n; i++) {
    cin >> a[i];
    freq[a[i]]++;
}

for (int i = 1; i <= n; i++) {
    if (freq[i] == 2) {
        cout << i << " ";
    }
}