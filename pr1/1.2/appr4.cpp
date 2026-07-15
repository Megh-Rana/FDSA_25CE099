int n;
cin >> n;
vector<int> a(n+1);

for (int i = 1; i <= n; i++) {
    cin >> a[i];
}

vector<int> result;

for (int i = 1; i <= n; i++) {
    int val = abs(a[i]);   
    if (a[val] < 0) {
        result.push_back(val); 
    } else {
        a[val] = -a[val];
    }
}