#include "BlockChain.h"

BlockChain::BlockChain() {
    chain.push_back(Block(0, "Genesis"));
    nDifficulty = 6;
}

void BlockChain::addBlock(Block newBlock){
    newBlock.prevHash = getLastBlock().getHash();
    newBlock.mineBlock(nDifficulty);
    chain.push_back(newBlock);
}

Block BlockChain::getLastBlock() const{
    return chain.back();
}