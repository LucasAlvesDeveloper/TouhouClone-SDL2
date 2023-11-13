#pragma once

#include <SDL2/SDL.h>

#define KEY_MACRO(detectableKey) detectableKey = SDL_SCANCODE_##detectableKey

enum Key
{
    // Alphabet Keys
    KEY_MACRO(A),
    KEY_MACRO(B),
    KEY_MACRO(C),
    KEY_MACRO(D),
    KEY_MACRO(E),
    KEY_MACRO(F),
    KEY_MACRO(G),
    KEY_MACRO(H),
    KEY_MACRO(I),
    KEY_MACRO(J),
    KEY_MACRO(K),
    KEY_MACRO(L),
    KEY_MACRO(M),
    KEY_MACRO(N),
    KEY_MACRO(O),
    KEY_MACRO(P),
    KEY_MACRO(Q),
    KEY_MACRO(R),
    KEY_MACRO(S),
    KEY_MACRO(T),
    KEY_MACRO(U),
    KEY_MACRO(V),
    KEY_MACRO(W),
    KEY_MACRO(X),
    KEY_MACRO(Y),
    KEY_MACRO(Z),

    // Arrow Keys
    KEY_MACRO(UP),
    KEY_MACRO(DOWN),
    KEY_MACRO(LEFT),
    KEY_MACRO(RIGHT),

    // Misc Keys
    KEY_MACRO(SPACE),

    // Modifier Keys
    KEY_MACRO(LSHIFT),
    KEY_MACRO(RSHIFT),
};

#undef KEY_MACRO