# Coffee Shop Clicker Game (SFML 3)

A 2D arcade clicker game developed in C++ using the SFML 3 framework. 

Originally written as a monolithic script inside a single file, I completely refactored the codebase to follow clean software architecture patterns and strict Object-Oriented Programming (OOP) principles.

<img width="1280" height="720" alt="cg" src="https://github.com/user-attachments/assets/0d3dc672-2ec4-4a0f-b1cf-21eb7ee7680a" />

# Architecture & Technical Highlights
- Separation of Concerns: Decoupled the monolithic logic into specialized execution layers: `Game` (engine lifecycle & window management), `GameManager` (gameplay state, mediator & interaction handling), `Menu` (item management), and `UI` (screen rendering overlay).
- Modern C++ Memory Management: Adapted assets to conform to SFML 3 memory constraints regarding non-copyable graphics objects by effectively utilizing `std::unique_ptr` containers and move semantics.
- Data Encapsulation: Isolated user interface layers, custom order lifecycles, and customer logic nodes to eliminate global state pollution.

# Tech Stack
- Language: C++17
- Framework: SFML 3 (Graphics, Window, System)
- Build System: CMake
