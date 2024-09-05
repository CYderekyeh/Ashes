#define maxs 100005
int trie[maxs][26], ed[maxs], node = 1;

void add(string t){
    int p = 0;
    for (int i = t.size()-1; i >= 0; i--){
        int c = t[i] - 'a';
        if (!trie[p][c]){
            trie[p][c] = node++;
        }
        p = trie[p][c];
    }
    ed[p] = true;
}

bool get(string s){
    int p = 0;
    for (int i = s.size()-1; i >= 0; i--){
        int c = s[i] - 'a';
        if (!trie[p][c]){
            return false;
        }
        p = trie[p][c];
    }
    return true;
}