#include <iostream>
#include <vector>
#include <string>

int getCardValue(const std::string& card) {
    if (card[0] >= '2' && card[0] <= '9') {
        return card[0] - '0';
    }
    return 10;
}

int main() {
    int T;
    std::cin >> T;

    for (int caseNum = 1; caseNum <= T; ++caseNum) {
        std::vector<std::string> pile(52);

        // Read deck bottom → top
        for (int i = 0; i < 52; ++i) {
            std::cin >> pile[i];
        }

        // Take top 25 into hand
        std::vector<std::string> hand(pile.end() - 25, pile.end());
        std::vector<std::string> table(pile.begin(), pile.end() - 25);

        int Y = 0;

        for (int i = 0; i < 3; ++i) {
            std::string topCard = table.back();
            table.pop_back();

            int X = getCardValue(topCard);
            Y += X;

            int removeCount = 10 - X;
            for (int j = 0; j < removeCount; ++j) {
                if (!table.empty()) {
                    table.pop_back();
                }
            }
        }

        // After 3 rounds: pile = table + hand
        std::vector<std::string> finalPile = table;
        finalPile.insert(finalPile.end(), hand.begin(), hand.end());

        std::cout << "Case " << caseNum << ": " << finalPile[Y - 1] << "\n";
    }

    return 0;
}