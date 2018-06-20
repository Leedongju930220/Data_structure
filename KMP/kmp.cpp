#include <stdio.h>
#include <string.h>
int n, m, sz;
char N[100010];
char M[100010];
int pi[100010];
int sol[100010];
void getPartialMatch(const char* M) {
    int m = strlen(M);
    int begin = 1, matched = 0;
    while (begin + matched < m) {
        if (M[begin + matched] == M[matched]) {
            ++matched;
            pi[begin + matched - 1] = matched;
        } else {
            if (matched == 0)
                ++begin;
            else {
                begin += matched - pi[matched - 1];
                matched = pi[matched - 1];
            }
        }
    }
}
void kmpSearch(const char* N, const char* M) {
    getPartialMatch(M);
    int n = strlen(N), m = strlen(M);
    int begin = 0, matched = 0;
    while (begin <= n - m) {
        if (matched < m && N[begin + matched] == M[matched]) {
            ++matched;
            if (matched == m) {
                sol[sz++] = begin;
            }
        } else {
            if (matched == 0) {
                ++begin;
            } else {
                begin += matched - pi[matched - 1];
                matched = pi[matched - 1];
            }
        }
    }
}
int main() {
    scanf("%d %s", &n, N);
    scanf("%d %s", &m, M);
    kmpSearch(N, M);
    printf("{");
    for (int i = 0; i < sz - 1; i++) {
        printf("%d,", sol[i]);
    }
    if (sz != 0) {
        printf("%d", sol[sz - 1]);
    }
    printf("}");
    return 0;
}
