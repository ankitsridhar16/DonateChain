#include "./Block/Block.h"

class BlockChain
{

    private:
        uint_fast32_t nDifficulty;
        std::vector<Block> chain;
        Block getLastBlock() const;
    public:
        BlockChain();
        void addBlock(Block newblock);
        ~BlockChain();
        
};
