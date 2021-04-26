// Copyright 2021 Kirillov Konstantin
#include "include/largest_subseq.h"
#include <vector>
#include <limits>
#include <algorithm>

Sequential::Sequential(std::vector <int> seq)
    :
    m_seq(seq) {
}

std::vector<int> Sequential::findLargSubseq(std::vector <int> fSec) {
    int n = fSec.size();
    std::vector<int> d(n + 1), pos(n + 1), prev(n);
    int length = 0;
    pos[0] = -1;
    d[0] = -std::numeric_limits<int>::max();

    for (int i = 1; i < n + 1; i ++) {
        d[i] = std::numeric_limits<int>::max();
    }

    for (int i = 0; i < n; i++) {
        int j = upper_bound(d.begin(), d.end(), fSec[i]) - d.begin();
        if (d[j - 1] < fSec[i] && fSec[i] < d[j]) {
            d[j] = fSec[i];
            pos[j] = i;
            prev[i] = pos[j - 1];
            length = std::max(length, j);
        }
    }

    std::vector<int> answer;
    int i = pos[length];
    if (length == 1) {
        answer.push_back(fSec[0]);
    } else {
        while (i != -1) {
            answer.push_back(fSec[i]);
            i = prev[i];
        }
    }
    std::reverse(answer.begin(), answer.end());
    return answer;
}

std::vector<int> Sequential::getLargSubseq() {
    std::vector<int> answer = findLargSubseq(Sequential::m_seq);
    return answer;
}
