#pragma once
// CCLightFlash stubs - raw OpenGL API removed in Geode 5.x / GD 2.2081.
// Classes are stubbed out so any remaining includes compile cleanly.
#include <Geode/Geode.hpp>
using namespace geode::prelude;

class CCLightFlash : public cocos2d::CCNode {
public:
    static CCLightFlash* create(cocos2d::CCPoint origin, cocos2d::ccColor3B color) { return nullptr; }
};

class CCLightStrip : public cocos2d::CCNode {
public:
    static CCLightStrip* create(float bW, float tW, float tH, float dur, float delay) { return nullptr; }
};