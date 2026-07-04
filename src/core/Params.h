#pragma once

#include <string>

struct ParamConfig {
    int layers = 6;
    int hiddenSize = 512;
    int vocabSize = 50000;
    int seqLength = 512;
    int batchSize = 32;
};

class Params {
public:
    static long long estimate(const ParamConfig &config);
    static std::string format(long long count);
};
