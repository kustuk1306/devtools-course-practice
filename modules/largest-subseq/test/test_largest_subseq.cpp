// Copyright 2021 Kirillov Konstantin

#include <gtest/gtest.h>
#include <string>
#include "include/largest_subseq.h"


TEST(largest_subseq, test_constructor) {
    std::vector<int> seqVec(3);
    seqVec[0] = 5;
    seqVec[1] = 6;
    seqVec[2] = 1;
    ASSERT_NO_THROW(Sequential seq(seqVec));
}

TEST(largest_subseq, mix_number) {
    int size = 6;
    std::vector<int> seqVec(6);
    std::vector<int> algAns;
    std::vector<int> stAns(4);
    seqVec[0] = -3;
    seqVec[1] = 2;
    seqVec[2] = 1;
    seqVec[3] = 4;
    seqVec[4] = 3;
    seqVec[5] = 7;
    Sequential seq(seqVec);
    algAns = seq.getLargSubseq();
    stAns[0] = -3;
    stAns[1] = 1;
    stAns[2] = 3;
    stAns[3] = 7;
    ASSERT_EQ(algAns, stAns);
}

TEST(largest_subseq, one_number) {
    std::vector<int> seqVec;
    std::vector<int> algAns;
    std::vector<int> stAns;
    seqVec.push_back(1);
    Sequential seq(seqVec);
    algAns = seq.getLargSubseq();
    stAns.push_back(1);
    ASSERT_EQ(algAns, stAns);
}

TEST(largest_subseq, some_subSeq_with_idential_size) {
    int size = 6;
    std::vector<int> seqVec(6);
    std::vector<int> algAns;
    std::vector<int> stAns(2);
    seqVec[0] = 5;
    seqVec[1] = 6;
    seqVec[2] = 1;
    seqVec[3] = 2;
    seqVec[4] = -3;
    seqVec[5] = -2;
    Sequential seq(seqVec);
    algAns = seq.getLargSubseq();
    stAns[0] = -3;
    stAns[1] = -2;
    ASSERT_EQ(algAns, stAns);
}

TEST(largest_subseq, subSeq_is_equally_seq) {
    int size = 5;
    std::vector<int> seqVec(5);
    std::vector<int> algAns;
    std::vector<int> stAns(5);
    seqVec[0] = 1;
    seqVec[1] = 2;
    seqVec[2] = 3;
    seqVec[3] = 4;
    seqVec[4] = 5;
    Sequential seq(seqVec);
    algAns = seq.getLargSubseq();
    stAns[0] = 1;
    stAns[1] = 2;
    stAns[2] = 3;
    stAns[3] = 4;
    stAns[4] = 5;
    ASSERT_EQ(algAns, stAns);
}

TEST(largest_subseq, subSeq_with_highter_than_zero) {
    int size = 5;
    std::vector <int> seqVec(5);
    std::vector <int> algAns(5);
    std::vector <int> stAns(3);
    seqVec[0] = 1;
    seqVec[1] = 2;
    seqVec[2] = 3;
    seqVec[3] = 0;
    seqVec[4] = 1;
    Sequential seq(seqVec);
    algAns = seq.getLargSubseq();
    stAns[0] = 1;
    stAns[1] = 2;
    stAns[2] = 3;
    ASSERT_EQ(algAns, stAns);
}

TEST(largest_subseq, subSeq_with_lower_than_zero) {
    int size = 5;
    std::vector <int> seqVec(5);
    std::vector <int> algAns(5);
    std::vector <int> stAns(3);
    seqVec[0] = -3;
    seqVec[1] = -2;
    seqVec[2] = -1;
    seqVec[3] = -5;
    seqVec[4] = -4;
    Sequential seq(seqVec);
    algAns = seq.getLargSubseq();
    stAns[0] = -3;
    stAns[1] = -2;
    stAns[2] = -1;
    ASSERT_EQ(algAns, stAns);
}

TEST(largest_subseq, one_ans_with_idential) {
    int size = 5;
    std::vector <int> seqVec(5);
    std::vector <int> algAns(5);
    std::vector <int> stAns;
    seqVec[0] = 3;
    seqVec[1] = 3;
    seqVec[2] = 3;
    seqVec[3] = 3;
    seqVec[4] = 3;
    Sequential seq(seqVec);
    algAns = seq.getLargSubseq();
    stAns.push_back(3);
    ASSERT_EQ(algAns, stAns);
}

TEST(largest_subseq, one_ans_with_another) {
    int size = 5;
    std::vector <int> seqVec(5);
    std::vector <int> algAns(5);
    std::vector <int> stAns;
    seqVec[0] = 5;
    seqVec[1] = 4;
    seqVec[2] = 3;
    seqVec[3] = 2;
    seqVec[4] = 1;
    Sequential seq(seqVec);
    algAns = seq.getLargSubseq();
    stAns.push_back(5);
    ASSERT_EQ(algAns, stAns);
}
