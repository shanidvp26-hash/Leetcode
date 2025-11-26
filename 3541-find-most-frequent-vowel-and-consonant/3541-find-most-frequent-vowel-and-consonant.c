bool isVowel(char c) {
    return (c=='a' || c=='e' || c=='i' || c=='o' || c=='u');
}

int maxFreqSum(char* s) {
    int freq[26] = {0};

    for (int i = 0; s[i] != '\0'; i++) {
        freq[s[i] - 'a']++;
    }

    int maxVowel = 0, maxConsonant = 0;

    for (int i = 0; i < 26; i++) {
        if (freq[i] == 0) continue;

        if (isVowel('a' + i)) {
            if (freq[i] > maxVowel)
                maxVowel = freq[i];
        } else {
            if (freq[i] > maxConsonant)
                maxConsonant = freq[i];
        }
    }

    return maxVowel + maxConsonant;
}