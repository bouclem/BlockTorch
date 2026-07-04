#pragma once

#include "Block.h"

class StopBlock : public Block {
    Q_OBJECT

public:
    explicit StopBlock(QWidget *parent = nullptr);
};
