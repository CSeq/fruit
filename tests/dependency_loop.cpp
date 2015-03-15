// expect-compile-error SelfLoopError<MutuallyConstructible2,MutuallyConstructible1>|this introduces a loop in the dependencies.
/*
 * Copyright 2014 Google Inc. All rights reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 * 
 *     http://www.apache.org/licenses/LICENSE-2.0
 * 
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <fruit/fruit.h>

struct MutuallyConstructible2;

struct MutuallyConstructible1 {
  INJECT(MutuallyConstructible1(const MutuallyConstructible2&)) {};
};

struct MutuallyConstructible2 {
  INJECT(MutuallyConstructible2(const MutuallyConstructible1&)) {};
};

fruit::Component<MutuallyConstructible1> mutuallyConstructibleComponent() {
  return fruit::createComponent();
}

int main() {
  return 0;
}
