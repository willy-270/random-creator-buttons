#include <Geode/Geode.hpp>
#include <Geode/modify/CreatorLayer.hpp>
#include <vector>
#include <random>

using namespace geode::prelude;

class $modify(mCreatorLayer, CreatorLayer) {

	bool init() {
		if (!CreatorLayer::init())
			return false;

		auto containerMenu = this->getChildByID("creator-buttons-menu");

		std::vector<CCNode*> buttons;
		std::vector<CCPoint> positions;

		for (auto button : CCArrayExt<CCNode*>(containerMenu->getChildren())) {
			buttons.push_back(button);
			positions.push_back(button->getPosition());
		}

		for (auto button : buttons) {
			auto randomIndex = std::rand() % positions.size();
			button->setPosition(positions[randomIndex]);
			positions.erase(positions.begin() + randomIndex);
		}

		return true;
	}
};