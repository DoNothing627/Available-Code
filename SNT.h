using namespace std;

const int maxN = int(1e8)+111;

int     prime[maxN], F[maxN];
int     primeNum, N;

void PrimeSieve() {
        for(int i = 2; i <= N; i++) {
                if (F[i] == 0) F[i] = prime[primeNum++] = i;
                int j = 0;
                while (j < primeNum && prime[j] <= F[i] && prime[j]*i <= N) {
                        F[prime[j]*i] = prime[j];
                        j++;
                }
        }
}