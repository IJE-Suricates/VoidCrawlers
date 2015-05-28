#include "play.h"
#include <core/font.h>
#include <core/rect.h>
#include <core/resourcesmanager.h>
#include <core/texture.h>

#define Y_BUTTON 266
#define W_BUTTON 305
#define H_BUTTON 40
#define W_BUTTON_BACK 140
#define H_BUTTON_BACK 60
#define SPACING 65

Play::Play(const string& next, const string& texture)
    : Level("play", next), m_texture(nullptr), m_logo(nullptr), m_slot1(nullptr),
        m_slot2(nullptr), m_slot3(nullptr)
{
    Environment *env = Environment::get_instance();

    m_texture = env->resources_manager->get_texture(texture);
    m_logo = env->resources_manager->get_texture("res/images/menu/babel-logo.png");
    m_slot_bar = env->resources_manager->get_texture("res/images/menu/slot-bar.png");
    
    double scale = env->canvas->scale();

    shared_ptr<Font> font = env->resources_manager->get_font("res/fonts/exo-2/Exo2.0-Regular.otf");
    env->canvas->set_font(font);
    font->set_size(22 * scale);
    
    const int x_button = (env->canvas->w() - W_BUTTON * scale) / 2;

    m_slot1 = new Button(this, "slot1", "res/images/menu/stripe.png", x_button,
        scale * (Y_BUTTON + SPACING), W_BUTTON * scale, H_BUTTON * scale);
    m_slot1->set_text("New Game");

    m_slot2 = new Button(this, "slot2", "res/images/menu/stripe.png", x_button,
        scale * (Y_BUTTON + SPACING * 2), W_BUTTON * scale, H_BUTTON * scale);
    m_slot2->set_text("New Game");

    m_slot3 = new Button(this, "slot3", "res/images/menu/stripe.png", x_button,
        scale * (Y_BUTTON + SPACING * 3), W_BUTTON * scale, H_BUTTON * scale);
    m_slot3->set_text("New Game");

    m_back = new Button(this, "back", "res/images/menu/button.png",
        (env->canvas->w() - W_BUTTON_BACK * scale)/2, env->canvas->h() - 149 * scale,
        W_BUTTON_BACK * scale, H_BUTTON_BACK * scale);
    m_back->set_text("Back");

    m_slot1->add_observer(this);
    m_slot2->add_observer(this);
    m_slot3->add_observer(this);
    m_back->add_observer(this);

    add_child(m_slot1);
    add_child(m_slot2);
    add_child(m_slot3);
    add_child(m_back);
}

void
Play::draw_self(double, double)
{
    Environment *env = Environment::get_instance();
    env->canvas->clear();
    
    env->canvas->draw(m_texture.get());

    double scale = env->canvas->scale();

    env->canvas->draw(m_logo.get(), (env->canvas->w() - m_logo->w() * scale)/2,
        25 * scale);

    env->canvas->draw(m_slot_bar.get(), (env->canvas->w() - m_slot_bar->w() * scale)/2,
        (Y_BUTTON + 30) * scale);

    set_position((env->canvas->w() - 115 * scale) / 2,  192 * scale);
    env->canvas->draw("PLAY GAME", bounding_box().x(), bounding_box().y(), Color(170, 215, 190));
}

bool
Play::on_message(Object *sender, MessageID id, Parameters)
{
    Button *button = dynamic_cast<Button *>(sender);

    if (id != Button::clickedID or not button)
    {
        return false;
    }

    if (button->id() == "slot1")
    {
        set_next("colony");
    }
    else if (button->id() == "slot2")
    {
        set_next("colony");
    }
    else if (button->id() == "slot3")
    {
        set_next("colony");
    }
    else if (button->id() == "back")
    {
        set_next("menu");
    }

    finish();

    return true;
}
