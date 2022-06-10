vector<ll> getPrime() {
    bool vis[10005];
    memset(vis, false, sizeof(vis));
    ll n = 10005;
    vector<ll> pr;

    for (ll i = 2; i < n; i++) {
        if (vis[i])
            continue;
        pr.push_back(i);
        for (ll j = 2 * i; j < n; j += i)
            vis[j] = true;
    }

    return pr;
}