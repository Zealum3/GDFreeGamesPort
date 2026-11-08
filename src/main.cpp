#include <Geode/Geode.hpp>
#include <Geode/modify/MenuLayer.hpp>
#include <Geode/modify/PauseLayer.hpp>
#include <Geode/modify/PlayLayer.hpp>
#include <Geode/modify/LoadingLayer.hpp>
#include <Geode/modify/EndLevelLayer.hpp>
#include <Geode/modify/GJGarageLayer.hpp>
#include <Geode/modify/LevelTools.hpp>
#include <Geode/Enums.hpp>
#include <Geode/utils/file.hpp>
#include "hooks/MoreGamesLayer.hpp"
#include "Meltdown/MeltdownSelectLayer.h"
#include "SubZero/SubZeroSelectLayer.h"
#include "World/ownWorldSelectLayer.h"

using namespace geode::prelude;
using namespace more;

class $modify(LoadingLayer)
{
    void loadAssets()
    {
        LoadingLayer::loadAssets();

        auto resourcesDir = geode::Mod::get()->getResourcesDir();
        auto zipFilePath = resourcesDir / "SpinOffGames.zip";
        auto unzipDir = resourcesDir / "SpinOffGames";

        auto result = geode::utils::file::Unzip::intoDir(zipFilePath, unzipDir);
        if (result.isErr()) {
            geode::log::warn("MoreGames: failed to unzip SpinOffGames.zip: {}", result.unwrapErr());
        }

        CCFileUtils::get()->addTexturePack(CCTexturePack{
            .m_id = "bitz.moregames/SpinOffGames",
            .m_paths = { unzipDir.string() }
        });

        auto* textureCache = CCTextureCache::sharedTextureCache();
        auto* spriteFrameCache = CCSpriteFrameCache::sharedSpriteFrameCache();

        textureCache->addImage("WorldSheet.png", false);
        spriteFrameCache->addSpriteFramesWithFile("WorldSheet.plist");
    }
};

class $modify(LevelTools)
{
    static GJGameLevel* getLevel(int levelID, bool getString)
    {
        GJGameLevel* level = GJGameLevel::create();

        switch (levelID) {
        case 1001:
            level->m_levelName = getAudioTitle(23);
            level->m_audioTrack = 23;
            level->m_coins = 3;
            level->m_stars = 1;
            level->m_difficulty = GJDifficulty::Easy;
            break;
        case 1002:
            level->m_levelName = getAudioTitle(24);
            level->m_audioTrack = 24;
            level->m_coins = 3;
            level->m_stars = 2;
            level->m_difficulty = GJDifficulty::Normal;
            break;
        case 1003:
            level->m_levelName = getAudioTitle(25);
            level->m_audioTrack = 25;
            level->m_coins = 3;
            level->m_stars = 3;
            level->m_difficulty = GJDifficulty::Hard;
            break;
        case 2001:
            level->m_levelName = getAudioTitle(27);
            level->m_audioTrack = 27;
            level->m_coins = 0;
            level->m_requiredCoins = 0;
            level->m_stars = 2;
            level->m_difficulty = GJDifficulty::Easy;
            break;
        case 2002:
            level->m_levelName = getAudioTitle(28);
            level->m_audioTrack = 28;
            level->m_coins = 0;
            level->m_requiredCoins = 0;
            level->m_stars = 2;
            level->m_difficulty = GJDifficulty::Easy;
            break;
        case 2003:
            level->m_levelName = getAudioTitle(29);
            level->m_audioTrack = 29;
            level->m_coins = 0;
            level->m_requiredCoins = 0;
            level->m_stars = 3;
            level->m_difficulty = GJDifficulty::Normal;
            break;
        case 2004:
            level->m_levelName = getAudioTitle(30);
            level->m_audioTrack = 30;
            level->m_coins = 0;
            level->m_requiredCoins = 0;
            level->m_stars = 3;
            level->m_difficulty = GJDifficulty::Normal;
            break;
        case 2005:
            level->m_levelName = getAudioTitle(31);
            level->m_audioTrack = 31;
            level->m_coins = 0;
            level->m_requiredCoins = 0;
            level->m_stars = 3;
            level->m_difficulty = GJDifficulty::Normal;
            break;
        case 2006:
            level->m_levelName = getAudioTitle(32);
            level->m_audioTrack = 32;
            level->m_coins = 0;
            level->m_requiredCoins = 0;
            level->m_stars = 3;
            level->m_difficulty = GJDifficulty::Normal;
            break;
        case 2007:
            level->m_levelName = getAudioTitle(33);
            level->m_audioTrack = 33;
            level->m_coins = 0;
            level->m_requiredCoins = 0;
            level->m_stars = 3;
            level->m_difficulty = GJDifficulty::Normal;
            break;
        case 2008:
            level->m_levelName = getAudioTitle(34);
            level->m_audioTrack = 34;
            level->m_coins = 0;
            level->m_requiredCoins = 0;
            level->m_stars = 3;
            level->m_difficulty = GJDifficulty::Normal;
            break;
        case 2009:
            level->m_levelName = getAudioTitle(35);
            level->m_audioTrack = 35;
            level->m_coins = 0;
            level->m_requiredCoins = 0;
            level->m_stars = 3;
            level->m_difficulty = GJDifficulty::Normal;
            break;
        case 2010:
            level->m_levelName = getAudioTitle(36);
            level->m_audioTrack = 36;
            level->m_coins = 0;
            level->m_requiredCoins = 0;
            level->m_stars = 3;
            level->m_difficulty = GJDifficulty::Normal;
            break;
        case 4001:
            level->m_levelName = getAudioTitle(37);
            level->m_audioTrack = 37;
            level->m_coins = 3;
            level->m_stars = 4;
            level->m_difficulty = GJDifficulty::Normal;
            break;
        case 4002:
            level->m_levelName = getAudioTitle(38);
            level->m_audioTrack = 38;
            level->m_coins = 3;
            level->m_stars = 6;
            level->m_difficulty = GJDifficulty::Hard;
            break;
        case 4003:
            level->m_levelName = getAudioTitle(39);
            level->m_audioTrack = 39;
            level->m_coins = 3;
            level->m_stars = 8;
            level->m_difficulty = GJDifficulty::Harder;
            break;
        default:
            return LevelTools::getLevel(levelID, getString);
        }

        level->m_levelString = LocalLevelManager::sharedState()->getMainLevelString(levelID);
        return level;
    }
};

class $modify(MenuLayer) {
    void onMoreGames(CCObject*) {
        auto* layer = more::MoreGamesLayer::create();
        addChild(layer, 100);
        layer->showLayer(false);
    }

    void onPlay(CCObject* sender) {
        Mod::get()->setSavedValue("onsubzero", 10);
        MenuLayer::onPlay(sender);
    }
};

class $modify(GJGarageLayer) {
    bool init() {
        Mod::get()->setSavedValue("onsubzero", 10);
        return GJGarageLayer::init();
    }

    void onBack(cocos2d::CCObject* sender) {
        auto pages = Mod::get()->getSavedValue<int>("onworldpages");

        if (pages != 0 && pages != 10) {
            auto World = ownWorldSelectLayer::create(0);
            auto scene = CCScene::create();
            scene->addChild(World);

            CCSize winSize = CCDirector::sharedDirector()->getWinSize();
            CCActionInterval* moveUp = CCMoveBy::create(0.23f, ccp(0, winSize.height));
            this->runAction(moveUp);

            if (pages == 1) {
                World->m_scrollLayer->instantMoveToPage(0);
                World->m_background->setColor(GameManager::sharedState()->colorForIdx(4));
            }
            else if (pages == 2) {
                World->m_scrollLayer->instantMoveToPage(1);
                World->m_background->setColor(GameManager::sharedState()->colorForIdx(6));
            }

            auto transitionScene = CCScene::create();
            CCActionInterval* moveDown = CCMoveBy::create(0.5f, ccp(0, -winSize.height));
            transitionScene->runAction(moveDown);

            auto transition = CCTransitionMoveInB::create(0.31f, scene);
            CCDirector::sharedDirector()->pushScene(transition);
        }
        else {
            GJGarageLayer::onBack(sender);
        }
    }
};

class $modify(PauseLayer) {
    void onQuit(CCObject* sender) {
        auto GM = GameManager::sharedState();
        int levelID = GM->m_playLayer->m_level->m_levelID;

        if (levelID > 1000 && levelID < 1004) {
            auto MeltdownScene = MeltdownSelectLayer::create(levelID - 1001);
            auto scene = CCScene::create();
            scene->addChild(MeltdownScene);
            CCDirector::sharedDirector()->replaceScene(CCTransitionFade::create(0.5, scene));
            PauseLayer::onQuit(sender);
            return;
        }

        if (levelID > 2000 && levelID < 2011) {
            auto scene = CCScene::create();
#ifdef GEODE_IS_WINDOWS
            auto specificWorldScene = ownWorldSelectLayer::create(0);
            int colorID = 4;
            if (levelID > 2005) {
                specificWorldScene->m_scrollLayer->instantMoveToPage(1);
                colorID = 6;
            }
            specificWorldScene->m_background->setColor(GameManager::sharedState()->colorForIdx(colorID));
            scene->addChild(specificWorldScene);
#endif
#ifdef GEODE_IS_ANDROID
            int page = (levelID > 2005) ? 1 : 0;
            auto worldScene = WorldSelectLayer::create(page);
            scene->addChild(worldScene);
#endif
            CCDirector::sharedDirector()->replaceScene(CCTransitionFade::create(0.5, scene));
            PauseLayer::onQuit(sender);
            return;
        }

        if (levelID > 4000 && levelID < 4004) {
            auto SubZeroScene = SubZeroSelectLayer::create(levelID - 4001);
            auto scene = CCScene::create();
            scene->addChild(SubZeroScene);
            CCDirector::sharedDirector()->replaceScene(CCTransitionFade::create(0.5, scene));
            PauseLayer::onQuit(sender);
            return;
        }

        PauseLayer::onQuit(sender);
    }
};

class $modify(EndLevelLayer) {
    void onMenu(CCObject* sender) {
        auto GM = GameManager::sharedState();
        int levelID = GM->m_playLayer->m_level->m_levelID;

        if (levelID > 1000 && levelID < 1004) {
            auto MeltdownScene = MeltdownSelectLayer::create(levelID - 1001);
            auto scene = CCScene::create();
            scene->addChild(MeltdownScene);
            CCDirector::sharedDirector()->replaceScene(CCTransitionFade::create(0.5, scene));
            EndLevelLayer::onMenu(sender);
            return;
        }

        if (levelID > 2000 && levelID < 2011) {
            auto scene = CCScene::create();
#ifdef GEODE_IS_WINDOWS
            auto specificWorldScene = ownWorldSelectLayer::create(0);
            int colorID = 4;
            if (levelID > 2005) {
                specificWorldScene->m_scrollLayer->instantMoveToPage(1);
                colorID = 6;
            }
            specificWorldScene->m_background->setColor(GameManager::sharedState()->colorForIdx(colorID));
            scene->addChild(specificWorldScene);
#endif
#ifdef GEODE_IS_ANDROID
            int page = (levelID > 2005) ? 1 : 0;
            auto worldScene = WorldSelectLayer::create(page);
            scene->addChild(worldScene);
#endif
            CCDirector::sharedDirector()->replaceScene(CCTransitionFade::create(0.5, scene));
            EndLevelLayer::onMenu(sender);
            return;
        }

        if (levelID > 4000 && levelID < 4004) {
            auto SubZeroScene = SubZeroSelectLayer::create(levelID - 4001);
            auto scene = CCScene::create();
            scene->addChild(SubZeroScene);
            CCDirector::sharedDirector()->replaceScene(CCTransitionFade::create(0.5, scene));
            EndLevelLayer::onMenu(sender);
            return;
        }

        EndLevelLayer::onMenu(sender);
    }
};

class $modify(PlayLayer) {
    void levelComplete() {
        PlayLayer::levelComplete();
        auto GSValues = GameStatsManager::sharedState()->m_playerStats;
        int coinsCollected = 0;
        int setPercentage;
        switch (m_level->m_levelID) {
        case 1001:
            if (GSValues->objectForKey("unique_1001_1") != nullptr) ++coinsCollected;
            if (GSValues->objectForKey("unique_1001_2") != nullptr) ++coinsCollected;
            if (GSValues->objectForKey("unique_1001_3") != nullptr) ++coinsCollected;
            setPercentage = coinsCollected * 100 / 3;
            GameManager::sharedState()->reportAchievementWithID("geometry.ach.mdcoin01", setPercentage, false);
            break;
        case 1002:
            if (GSValues->objectForKey("unique_1002_1") != nullptr) ++coinsCollected;
            if (GSValues->objectForKey("unique_1002_2") != nullptr) ++coinsCollected;
            if (GSValues->objectForKey("unique_1002_3") != nullptr) ++coinsCollected;
            setPercentage = coinsCollected * 100 / 3;
            GameManager::sharedState()->reportAchievementWithID("geometry.ach.mdcoin02", setPercentage, false);
            break;
        case 1003:
            if (GSValues->objectForKey("unique_1003_1") != nullptr) ++coinsCollected;
            if (GSValues->objectForKey("unique_1003_2") != nullptr) ++coinsCollected;
            if (GSValues->objectForKey("unique_1003_3") != nullptr) ++coinsCollected;
            setPercentage = coinsCollected * 100 / 3;
            GameManager::sharedState()->reportAchievementWithID("geometry.ach.mdcoin03", setPercentage, false);
            break;
        case 4001:
            if (GSValues->objectForKey("unique_4001_1") != nullptr) ++coinsCollected;
            if (GSValues->objectForKey("unique_4001_2") != nullptr) ++coinsCollected;
            if (GSValues->objectForKey("unique_4001_3") != nullptr) ++coinsCollected;
            setPercentage = coinsCollected * 100 / 3;
            GameManager::sharedState()->reportAchievementWithID("geometry.ach.subzero.coins001", setPercentage, false);
            break;
        case 4002:
            if (GSValues->objectForKey("unique_4002_1") != nullptr) ++coinsCollected;
            if (GSValues->objectForKey("unique_4002_2") != nullptr) ++coinsCollected;
            if (GSValues->objectForKey("unique_4002_3") != nullptr) ++coinsCollected;
            setPercentage = coinsCollected * 100 / 3;
            GameManager::sharedState()->reportAchievementWithID("geometry.ach.subzero.coins002", setPercentage, false);
            break;
        case 4003:
            if (GSValues->objectForKey("unique_4003_1") != nullptr) ++coinsCollected;
            if (GSValues->objectForKey("unique_4003_2") != nullptr) ++coinsCollected;
            if (GSValues->objectForKey("unique_4003_3") != nullptr) ++coinsCollected;
            setPercentage = coinsCollected * 100 / 3;
            GameManager::sharedState()->reportAchievementWithID("geometry.ach.subzero.coins003", setPercentage, false);
            break;
        }
    }
};