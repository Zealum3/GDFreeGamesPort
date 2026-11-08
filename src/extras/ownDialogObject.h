#pragma once

#include <Geode/Geode.hpp>

using namespace geode::prelude;
/*
 * ownDialogObject - wrapper around the game-native DialogObject.
 * In GD 2.2081 / Geode 5.x the Windows binary offset changed,
 * so we now delegate directly through the Geode bindings instead
 * of using a hard-coded address.
 *
 * Original idea from FigmentBoy (DialogHandler) and thesillydoggo.
 */
class ownDialogObject : public cocos2d::CCObject {
public:
    static ownDialogObject* create(
        std::string title,
        std::string text,
        int type,
        float text_scale,
        bool is_unskippable,
        _ccColor3B textColor)
    {
        // Delegate to the native DialogObject through Geode bindings.
        auto* native = DialogObject::create(
            title.c_str(),
            text.c_str(),
            type,
            text_scale,
            is_unskippable,
            textColor
        );
        // DialogObject IS a CCObject so the cast is safe.
        return reinterpret_cast<ownDialogObject*>(native);
    }
};