#pragma once

#include "Block.h"

class StartBlock : public Block {
    Q_OBJECT

public:
    explicit StartBlock(QWidget *parent = nullptr);
};
