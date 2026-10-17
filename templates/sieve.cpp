const int M = 4 * 1e7;
vector<int> u(M + 1);
vector<int> primes;
void sieve() {
    for (int i = 2; i <= M; i++) {
        if (!u[i]) {
            u[i] = i;
            primes.push_back(i);
        }
        for (int j = 0;
             j < primes.size() and primes[j] <= u[i] and i * primes[j] <= M;
             j++) {
            u[primes[j] * i] = primes[j];
        }
    }
}
