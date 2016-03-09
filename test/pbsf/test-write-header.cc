/*

    Copyright 2016 Carl Lei

    This file is part of Bamboo Shoot 3.

    Bamboo Shoot 3 is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    Bamboo Shoot 3 is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with Bamboo Shoot 3.  If not, see <http://www.gnu.org/licenses/>.

    Carl Lei <xecycle@gmail.com>

*/

#include <sstream>
#include <cassert>

#include <bs3/pbsf/pbsf.hh>

PBSF_DECLARE_REALM(TestRealm, 0x04030201,
                   PBSF_REGISTER_TYPE(1, int));

int main()
{

  std::ostringstream out;

  pbsf::write_header(out, TestRealm());

  assert(out.str() == "pbs3\x1\x2\x3\x4");

  return 0;
}
