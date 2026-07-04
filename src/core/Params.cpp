#include "Params.h"

#include <cmath>
#include <sstream>

long long Params::estimate(const ParamConfig &config)
{
    long long total = 0;

    long long embeddingParams = static_cast<long long>(config.vocabSize) * config.hiddenSize;
    total += embeddingParams;

    long long layerParams = 0;
    layerParams += static_cast<long long>(config.hiddenSize) * config.hiddenSize * 4;
    layerParams += static_cast<long long>(config.hiddenSize) * 4;
    layerParams += static_cast<long long>(config.hiddenSize) * config.hiddenSize * 4;
    layerParams += static_cast<long long>(config.hiddenSize) * 4;
    layerParams += static_cast<long long>(config.hiddenSize) * config.hiddenSize;
    layerParams += static_cast<long long>(config.hiddenSize);
    total += layerParams * config.layers;

    long long outputParams = static_cast<long long>(config.hiddenSize) * config.vocabSize;
    total += outputParams;

    return total;
}

std::string Params::format(long long count)
{
    if (count >= 1000000000) {
        std::ostringstream oss;
        oss << (count / 1000000000.0) << "B";
        return oss.str();
    }
    if (count >= 1000000) {
        std::ostringstream oss;
        oss << (count / 1000000.0) << "M";
        return oss.str();
    }
    if (count >= 1000) {
        std::ostringstream oss;
        oss << (count / 1000.0) << "K";
        return oss.str();
    }
    return std::to_string(count);
}
