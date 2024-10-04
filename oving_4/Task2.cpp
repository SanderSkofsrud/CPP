#include <gtkmm.h>

class Window : public Gtk::Window {
public:
    Gtk::Box box{Gtk::ORIENTATION_VERTICAL};
    Gtk::Entry entryFirstName, entryLastName;
    Gtk::Button button{"Combine names"};
    Gtk::Label label, labelFirstName{"First Name"}, labelLastName{"Last Name"};

    Window() {
        // Add widgets to box
        box.pack_start(labelFirstName);
        box.pack_start(entryFirstName);
        box.pack_start(labelLastName);
        box.pack_start(entryLastName);
        box.pack_start(button);
        box.pack_start(label);

        // Set window title
        set_title("Name Combiner");

        // Set button sensitivity based on input
        button.set_sensitive(false);
        entryFirstName.signal_changed().connect([this]() {
            toggle_button();
        });
        entryLastName.signal_changed().connect([this]() {
            toggle_button();
        });

        // Set button click action
        button.signal_clicked().connect([this]() {
            label.set_text(entryFirstName.get_text() + " " + entryLastName.get_text());
        });

        // Add box to the window and show everything
        add(box);
        show_all_children();
    }

private:
    void toggle_button() {
        if (entryFirstName.get_text().empty() || entryLastName.get_text().empty()) {
            button.set_sensitive(false);
        } else {
            button.set_sensitive(true);
        }
    }
};

int main(int argc, char *argv[]) {
    auto app = Gtk::Application::create(argc, argv, "org.gtkmm.example");
    Window window;
    return app->run(window);
}
