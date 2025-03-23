# One-Time-Pad-Implementation-C
An implementation of the uncrackable encryption algorithm


## Project Structure

One-Time-Pad-Implementation-C/

- **One-Time-Pad-Implementation-C/**
  - **universal/**                  
    - **one-time-pad-universal_ENC.c**        
    - **one-time-pad-universal_DEC.c**     
  - **linux/**
      - **one-time-pad-linux_ENC.c**
      - **one-time-pad-linux_DEC.c**        
  - **README.md**             


## Description

> In cryptography, the one-time pad (OTP) is an encryption technique that cannot be cracked. It requires the use of a single-use pre-shared key that is larger than or equal to the size of the message being sent. In this technique, a plaintext is paired with a random secret key (also referred to as a one-time pad). Then, each bit or character of the plaintext is encrypted by combining it with the corresponding bit or character from the pad using modular addition.

- The resulting ciphertext is impossible to decrypt or break if the following four conditions are met:
   - The key must be at least as long as the plaintext.
   - The key must be truly random.
   - The key must never be reused in whole or in part.
   - The key must be kept completely secret by the communicating parties.
 
- In the universal/ directory, achieveing a truly random number wasn't possible so I used srand() to generate a random seed using the time() and feed that seed to rand()
- While in the linux/ directory, achieving it was very easy as I used /dev/urandom file
  > It's backed by a CSPRNG that is seeded with entropy (a value that provides randomness) from environmental noise, collected from device drivers and other sources. Users can obtain random numbers from the CSPRNG simply by reading the file.
