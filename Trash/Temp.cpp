// sf::RenderWindow window(sf::VideoMode({1000, 1000}), "NVK", sf::Style::Close || sf::Style::Titlebar);
//     std::cout << "START PROGRAM" << std::endl;

//     //Font
//     sf::Font font;
//     if(!font.openFromFile("Arial.ttf"))
//     {
//         std::cout << "Can't load font" << std::endl;
//     }
//     std::vector<sf::RectangleShape> lines;
//     //Line
//     sf::RectangleShape line(sf::Vector2f(1000, 1));
//     line.setPosition({0, 100});
//     line.setFillColor(sf::Color::Blue);
//     //Line1
//     sf::RectangleShape line1(sf::Vector2f(1, 100));
//     line1.setPosition({100, 0});
//     line1.setFillColor(sf::Color::Blue);
//     //Line2
//     sf::RectangleShape line2(sf::Vector2f(1, 100));
//     line2.setPosition({300, 0});
//     line2.setFillColor(sf::Color::Blue);
//     //Line3
//     sf::RectangleShape line3(sf::Vector2f(1, 100));
//     line3.setPosition({500, 0});
//     line3.setFillColor(sf::Color::Blue);
//     //Line4
//     sf::RectangleShape line4(sf::Vector2f(1, 100));
//     line4.setPosition({700, 0});
//     line4.setFillColor(sf::Color::Blue);
//     //Line5
//     sf::RectangleShape line5(sf::Vector2f(1, 100));
//     line5.setPosition({900, 0});
//     line5.setFillColor(sf::Color::Blue);
//     //Push
//     lines.push_back(line1);
//     lines.push_back(line2);
//     lines.push_back(line3);
//     lines.push_back(line4);
//     lines.push_back(line5);
//     //Vector text
//     std::vector<sf::Text> texts;
//     //Text1
//     sf::Text text1(font, "ID", 20);
//     float x1 = text1.getGlobalBounds().size.x;
//     float y1 = text1.getGlobalBounds().size.y;
//     text1.setPosition({50 - x1/2, 50 - y1/2});
//     //Text2
//     sf::Text text2(font, "NAME", 20);
//     float x2 = text2.getGlobalBounds().size.x;
//     float y2 = text2.getGlobalBounds().size.y;
//     text2.setPosition({200 - x2/2, 50 - y2/2});
//     //Text3
//     sf::Text text3(font, "AUTHOR", 20);
//     float x3 = text3.getGlobalBounds().size.x;
//     float y3 = text3.getGlobalBounds().size.y;
//     text3.setPosition({400 - x3/2, 50 - y3/2});
//     //Text4
//     sf::Text text4(font, "TYPE", 20);
//     float x4 = text4.getGlobalBounds().size.x;
//     float y4 = text4.getGlobalBounds().size.y;
//     text4.setPosition({600 - x1/2, 50 - y1/2});
//     //Text5
//     sf::Text text5(font, "PRICE", 20);
//     float x5 = text5.getGlobalBounds().size.x;
//     float y5 = text5.getGlobalBounds().size.y;
//     text5.setPosition({800 - x5/2, 50 - y5/2});
//     //Text6
//     sf::Text text6(font, "STATUS", 20);
//     float x6 = text6.getGlobalBounds().size.x;
//     float y6 = text6.getGlobalBounds().size.y;
//     text6.setPosition({950 - x6/2, 50 - y6/2});
//     //Push
//     texts.push_back(text1);
//     texts.push_back(text2);
//     texts.push_back(text3);
//     texts.push_back(text4);
//     texts.push_back(text5);
//     texts.push_back(text6);
//     //Main loop
//     while(isMainWindowTurnOn && isPhieuMuonWindowTurnOn == false)
//     {
//         while(const std::optional event = window.pollEvent())
//         {
//             if(event->is<sf::Event::Closed>())
//             {
//                 window.close();
//             }
//             else if(auto* keyPressed = event->getIf<sf::Event::KeyPressed>())
//             {
//                 if(keyPressed->scancode == sf::Keyboard::Scancode::Escape)
//                 {
//                     window.close();
//                     isMainWindowTurnOn = false;
//                     isRunningProgram = false;
//                 }
//             }
//         }
//         if(isRunningProgram == false)
//         {
//             break;
//         }
//         window.clear();
//         //Draw
//         for(const auto line : lines)
//         {
//             window.draw(line);
//         }
//         for(const auto text : texts)
//         {
//             window.draw(text);
//         }
//         window.draw(line);
//         window.display();
//     }