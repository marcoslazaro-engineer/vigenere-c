 # Vigenere Cipher in C

This repository contains a clean and modular implementation of the **Vigenere cipher**, written in C.  
It allows you to encrypt and decrypt messages using a user-defined keyword.  
Perfect for learning polyalphabetic cryptography and C programming fundamentals.

---

##  What is the Vigenere Cipher?

The Vigenere cipher is a classic encryption method that improves upon the Caesar cipher by using a keyword to vary the shift for each letter.  
It applies a different Caesar shift for each letter based on the corresponding letter of the key.

---

##  How it works:

- **Encryption:** Each letter is shifted forward by the alphabetical index of the corresponding key letter (A=0, B=1, ...).
- **Decryption:** Each letter is shifted backward by that same value.
- The key repeats if it is shorter than the message.

---

## Example (Key = LEMON):

Plaintext : ATTACKATDAWN
Key : LEMONLEMONLE
Encrypted : LXFOPVEFRNHR


Only alphabetic characters are processed.  
Spaces, digits, and symbols remain unchanged.

---

##  Features

✅ Encrypt and decrypt from user input  
✅ Works with uppercase and lowercase letters  
✅ Skips non-letter characters  
✅ Clean, readable and modular C code  
✅ Cross-platform (Linux/Windows compatible)  
✅ Loop for multiple operations in one session  

---

##  How to Compile?

```bash
gcc main.c -o vigenere
## How to run?
./vigenere       # on Linux/macOS
vigenere.exe     # on Windows (Code::Blocks or cmd)
