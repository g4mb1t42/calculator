#include <stdio.h> 
#include <string> 
#include<iostream>
#include <cmath>
using namespace std;
double Calc(double x, string op1, double y, string op2, double z, string op3, double t);



int main() {
	double son = 0.0;
	double x = 0.0;
	double y = 0.0;
	double z = 0.0;
	double t = 0.0;
	string op1 = "+";
	string op2 = "+";
	string op3 = "+";
	
	while (true)
	{
		cin >> x >> op1 >> y;
		if (cin.get() == '\n') {
			son = Calc(x, op1, y, op2, z, op3, t);
			cout << son;
			cout << "\n";
			son = 0.0;
			x = 0.0;
			y = 0.0;
			z = 0.0;
			t = 0.0;
			op1 = "+";
			op2 = "+";
			op3 = "+";
			continue;
		}
		cin >> op2 >> z;
		if (cin.get() == '\n') {
			son = Calc(x, op1, y, op2, z, op3, t);
			cout << son;
			cout << "\n";
			son = 0.0;
			x = 0.0;
			y = 0.0;
			z = 0.0;
			t = 0.0;
			op1 = "+";
			op2 = "+";
			op3 = "+";
			continue;
		}
		cin >> op3 >> t;
		if (cin.get() == '\n') {
			son = Calc(x, op1, y, op2, z, op3, t);
			cout << son;
			cout << "\n";
			son = 0.0;
			x = 0.0;
			y = 0.0;
			z = 0.0;
			t = 0.0;
			op1 = "+";
			op2 = "+";
			op3 = "+";
			continue;
		}
		son = 0.0;
		x = 0.0;
		y = 0.0;
		z = 0.0;
		t = 0.0;
		op1 = "+";
		op2 = "+";
		op3 = "+";
	

	}

}
double ConvertFrom10(double value, int base)
{
	if (base < 2 || base > 36)
		return 0;

	bool isNegative = (value < 0);
	if (isNegative)
		value *= -1;

	// NOTE: it's probably possible to reserve string based on value
	string output;

	do
	{
		char digit = std::fmod(value, base);

		// Convert to appropriate base character
		// 0-9
		if (digit < 10)
			digit += '0';
		// A-Z
		else
			digit = digit + 'A' - 10;

		// Append digit to string (in reverse order)
		output += digit;

		value /= base;

	} while (value > 0);

	if (isNegative)
		output += '-';

	// Reverse the string - NOTE: could be done with std::reverse
	reverse(output.begin(), output.end());
	double doub = std::stof(output);
	return doub;
}

double Calc(double x, string op1, double y, string op2, double z, string op3, double t) {
	double sonuc = 0.0;
	if (op1 == "^")
	{
		double tmp1 = 1.0;
		for (int i = 0;i < y;++i)
		{
			tmp1 = tmp1 * x;

		}
		sonuc = tmp1;
		if (op2 == "+" || "-")
		{
			if (op3 == "+") {
				if (op2 == "+")
				{
					sonuc = sonuc + z;
					sonuc = sonuc + t;
				}
				else if (op2 == "-")
				{
					sonuc = sonuc - z;
					sonuc = sonuc + t;
				}
			}
			else if (op3 == "-") {
				if (op2 == "+")
				{
					sonuc = sonuc + z;
					sonuc = sonuc - t;
				}
				else if (op2 == "-")
				{
					sonuc = sonuc - z;
					sonuc = sonuc - t;
				}
	
			}
			else if (op3 == "*") {
				int temp = 0;
				temp = z * t;
				if (op2 == "+")
				{
					sonuc = sonuc + temp;
				}
				else if (op2 == "-")
				{
					sonuc = sonuc - temp;
				}
			}
			else if (op3 == "/") {
				int temp = 0;
				temp = z / t;
				if (op2 == "+")
				{
					sonuc = sonuc + temp;
				}
				else if (op2 == "-")
				{
					sonuc = sonuc - temp;
				}
			}
			else if (op3 == "%") {
				if (op2 == "+")
				{
					sonuc = sonuc + z;
					sonuc = std::fmod(sonuc, t);
				}
				else if (op2 == "-")
				{
					sonuc = sonuc - z;
					sonuc = std::fmod(sonuc, t);
				}


			}
			else if (op3 == "^") {
				double tmp2 = 1.0;
				for (int i = 0;i < t;++i)
				{
					tmp2 = tmp2 * z;

				}
				if (op2 == "+")
				{
					sonuc = sonuc + tmp2;
				}
				if (op2 == "-")
				{
					sonuc = sonuc - tmp2;
				}
			}
			else if (op3 == "base") {
				if (op2 == "+")
				{
					sonuc = sonuc + z;
					sonuc = ConvertFrom10(sonuc, t);
				}
				else if (op2 == "-")
				{
					sonuc = sonuc - z;
					sonuc = ConvertFrom10(sonuc, t);
				}
			}

		}
		if (op2 == "/" || "*")
		{
		if (op3 == "^")
		{
			double tmp4 = 1.0;
			for (int i = 0;i < t;++i)
			{
				tmp4 = z * tmp4;

			}
			if (op2 == "*")
			{
				sonuc = sonuc * tmp4;
			}
			else if (op2 == "/")
			{
				sonuc = sonuc / tmp4;
			}

		}
		else if (op3 == "*" || "/")
		{
			if (op2 == "*")
			{
				sonuc = sonuc * z;
				if (op3 == "*")
				{
					sonuc = sonuc * t;

				}
				else if (op3 == "/")
				{
					sonuc = sonuc / t;

				}
			}
			else if (op2 == "/")
			{
				sonuc = sonuc / z;
				if (op3 == "*")
				{
					sonuc = sonuc * t;

				}
				else if (op3 == "/")
				{
					sonuc = sonuc / t;

				}
			}

		}
		else if (op3 == "+" || "-")
		{
			if (op2 == "*")
			{
				sonuc = sonuc * z;
				if (op3 == "-")
				{
					sonuc = sonuc - t;
				}
				else if (op3 == "+")
				{
					sonuc = sonuc + t;
				}

			}
			else if (op2 == "/")
			{
				sonuc = sonuc / z;
				if (op3 == "-")
				{
					sonuc = sonuc - t;
				}
				else if (op3 == "+")
				{
					sonuc = sonuc + t;
				}


			}

		}
		else if (op3 == "%")
		{
			if (op2 == "*")
			{
				sonuc = sonuc * t;
				sonuc = std::fmod(sonuc, t);
			}
			else if (op2 == "/")
			{
				sonuc = sonuc / t;
				sonuc = std::fmod(sonuc, t);
			}

		}
		else if (op3 == "base")
		{
			if (op2 == "*")
			{
				sonuc = sonuc * z;
				sonuc = ConvertFrom10(sonuc, t);
			}
			else if (op2 == "/")
			{
				sonuc = sonuc / z;
				sonuc = ConvertFrom10(sonuc, t);
			}
		}

 }
		if (op2 == "%")
		{
		if (op3 == "+") {
			double temp = 0.0;
			temp = z + t;
			sonuc = std::fmod(sonuc, temp);
		  }
		else if (op3 == "-") {
			double temp = 0.0;
			temp = z - t;
			sonuc = std::fmod(sonuc, temp);
		}
		else if (op3 == "*") {
			double temp = 0.0;
			temp = z * t;
			sonuc = std::fmod(sonuc, temp);
		}
		else if (op3 == "/") {
			double temp = 0.0;
			temp = z / t;
			sonuc = std::fmod(sonuc, temp);
		}
		else if (op3 == "%") {
			sonuc = std::fmod(sonuc,z);
			sonuc = std::fmod(sonuc, t);
	
		}
		else if (op3 == "^") {
			double tmp2 = 1.0;
			for (int i = 0;i < t;++i)
			{
				tmp2 = tmp2 * z;

			}
			sonuc = std::fmod(sonuc, tmp2);
		}
		else if (op3 == "base") {
			sonuc = std::fmod(sonuc, z);
			sonuc = ConvertFrom10(sonuc, t);
		}

		}
		if (op2 == "base")
		{
		if (op3 == "+") {
			double temp = 0.0;
			temp = z + t;
			sonuc = ConvertFrom10(sonuc, temp);
		}
		else if (op3 == "-") {
			double temp = 0.0;
			temp = z - t;
			sonuc = ConvertFrom10(sonuc, temp);
		}
		else if (op3 == "*") {
			double temp = 0.0;
			temp = z * t;
			sonuc = ConvertFrom10(sonuc, temp);

		}
		else if (op3 == "/") {
			double temp = 0.0;
			temp = z / t;
			sonuc = ConvertFrom10(sonuc, temp);
		}
		else if (op3 == "%") {
			double temp = std::fmod(z, t);
			sonuc = ConvertFrom10(sonuc, temp);

		}
		else if (op3 == "^") {
			double tmp2 = 1;
			for (int i = 0;i < t;++i)
			{
				tmp2 = tmp2 * z;

			}
			sonuc = ConvertFrom10(sonuc, tmp2);
		}
		else if (op3 == "base") {
			
			sonuc = ConvertFrom10(sonuc, z);
			sonuc = ConvertFrom10(sonuc, t);
		
		}
		}
		if (op2 == "^")
		{
			double tmp2 = 1.0;
			for (int i = 0;i < z;++i)
			{
				tmp2 = tmp2 * sonuc;

			}
			sonuc = tmp2;
			if (op3 == "^")
			{
				double tmp3 = 1.0;
				for (int i = 0;i < t;++i)
				{
					tmp3 = tmp3 * sonuc;

				}
				sonuc = tmp3;
				return sonuc;
			}
			else if (op3 == "+")
			{
				sonuc = sonuc + t;
			}
			else if (op3 == "-")
			{
				sonuc = sonuc - t;
			}
			else if (op3 == "*")
			{
				sonuc = sonuc * t;
			}
			else if (op3 == "/")
			{
				sonuc = sonuc / t;
			}
			else if (op3 == "%")
			{
				sonuc = std::fmod(sonuc, t);
			}
			else if (op3 == "base")
			{
				sonuc = ConvertFrom10(sonuc, t);
			}

		}
	}
	else if (op1 == "*")
	{
	if (op2 == "^")
	{
		double tmp1 = 1.0;
		for (int i = 0;i < z;++i)
		{
			tmp1 = tmp1 * y;

		}
		if (op3 == "^")
		{
			double tmp2 = 1.0;
			for (int i = 0;i < t;++i)
			{
				tmp2 = tmp2 * tmp1;

			}
			sonuc = x * tmp2;
		
		}
		else
		{
			sonuc = x * tmp1;
			if (op3 == "+")
			{
				sonuc = sonuc + t;
			}
			else if (op3 == "-")
			{
				sonuc = sonuc - t;
			}
			else if (op3 == "*")
			{
				sonuc = sonuc * t;
			}
			else if (op3 == "/")
			{
				sonuc = sonuc / t;
			}
			else if (op3 == "%")
			{
				sonuc = std::fmod(sonuc, t);
			}
			else if (op3 == "base")
			{
				sonuc = ConvertFrom10(sonuc, t);
			}
		}
	}
	else if (op2 == "+")
	{
		sonuc = x * y;
		if (op3 == "+") {
			sonuc = sonuc + z;
			sonuc = sonuc + t;
		}
		else if (op3 == "-") {
			sonuc = sonuc + z;
			sonuc = sonuc - t;
		}
		else if (op3 == "*") {
			double temp = 0.0;
			temp = z * t;
			sonuc = sonuc + temp;
		}
		else if (op3 == "/") {
			double temp = 0.0;
			temp = z / t;
			sonuc = sonuc + temp;
		}
		else if (op3 == "%") {
			sonuc = sonuc + z;
			sonuc = std::fmod(sonuc, t);
		}
		else if (op3 == "^") {
			double tmp1 = 1.0;
			for (int i = 0;i < t;++i)
			{
				tmp1 = tmp1 * z;

			}
			sonuc = sonuc + tmp1;
		
		}
		else if (op3 == "base") {
			sonuc = sonuc + z;
			sonuc = ConvertFrom10(sonuc, t);
		}
	
	
	
	}
	else if (op2 == "-")
	{
		sonuc = x * y;
		if (op3 == "+") {
			sonuc = sonuc - z;
			sonuc = sonuc + t;
		}
		else if (op3 == "-") {
			sonuc = sonuc - z;
			sonuc = sonuc - t;
		}
		else if (op3 == "*") {
			double temp = 0.0;
			temp = z * t;
			sonuc = sonuc - temp;
		}
		else if (op3 == "/") {
			double temp = 0.0;
			temp = z / t;
			sonuc = sonuc - temp;
		}
		else if (op3 == "%") {
			sonuc = sonuc - z;
			sonuc = std::fmod(sonuc, t);
		}
		else if (op3 == "^") {
			double tmp1 = 1.0;
			for (int i = 0;i < t;++i)
			{
				tmp1 = tmp1 * z;

			}
			sonuc = sonuc - tmp1;

		}
		else if (op3 == "base") {
			sonuc = sonuc - z;
			sonuc = ConvertFrom10(sonuc, t);
		}
	
	}
	else if (op2 == "*")
	{
		sonuc = x * y;
		if (op3 == "+")
		{
			sonuc = sonuc * z;
			sonuc = sonuc + t;
		}
		else if (op3 == "-")
		{
			sonuc = sonuc * z;
			sonuc = sonuc - t;
		}
		else if (op3 == "*")
		{
			sonuc = sonuc * z;
			sonuc = sonuc * t;
		}
		else if (op3 == "/")
		{
			sonuc = sonuc * z;
			sonuc = sonuc / t;
		}
		else if (op3 == "^")
		{
			double tmp1 = 1.0;
			for (int i = 0;i < t;++i)
			{
				tmp1 = tmp1 * z;

			}
			sonuc = sonuc * tmp1;
		
		}
		else if (op3 == "base")
		{
			sonuc = sonuc * z;
			sonuc = ConvertFrom10(sonuc, t);
		}
		else if (op3 == "%")
		{
			sonuc = sonuc * z;
			sonuc = std::fmod(sonuc, t);

		}
	

    }
	else if (op2 == "/")
	{
		sonuc = x * y;
		if (op3 == "+")
		{
			sonuc = sonuc / z;
			sonuc = sonuc + t;
		}
		else if (op3 == "-")
		{
			sonuc = sonuc / z;
			sonuc = sonuc - t;
		}
		else if (op3 == "*")
		{
			sonuc = sonuc / z;
			sonuc = sonuc * t;
		}
		else if (op3 == "/")
		{
			sonuc = sonuc / z;
			sonuc = sonuc / t;
		}
		else if (op3 == "^")
		{
			double tmp1 = 1.0;
			for (int i = 0;i < t;++i)
			{
				tmp1 = tmp1 * z;

			}
			sonuc = sonuc / tmp1;

		}
		else if (op3 == "base")
		{
			sonuc = sonuc / z;
			sonuc = ConvertFrom10(sonuc, t);
		}
		else if (op3 == "%")
		{
			sonuc = sonuc / z;
			sonuc = std::fmod(sonuc, t);

		}
	}
	else if (op2 == "%")
	{
		sonuc = x * y;
		if (op3 == "+")
		{
			double temp = 0.0;
			temp = z + t;
			sonuc = std::fmod(sonuc, temp);
		}
		else if (op3 == "-")
		{
			double temp = 0.0;
			temp = z - t;
			sonuc = std::fmod(sonuc, temp);
		}
		else if (op3 == "*")
		{
			double temp = 0.0;
			temp = z * t;
			sonuc = std::fmod(sonuc, temp);
		}
		else if (op3 == "/")
		{
			double temp = 0.0;
			temp = z / t;
			sonuc = std::fmod(sonuc, temp);
		}
		else if (op3 == "%")
		{
			sonuc = std::fmod(sonuc, z);
			sonuc = std::fmod(sonuc, t);
		}
		else if (op3 == "^")
		{
			double tmp1 = 1.0;
			for (int i = 0;i < t;++i)
			{
				tmp1 = tmp1 * z;

			}
			sonuc = std::fmod(sonuc, tmp1);
		
		
		}
		else if (op3 == "base")
		{
			sonuc = std::fmod(sonuc, z);
			sonuc = ConvertFrom10(sonuc, t);
		}
	


    }
	else if (op2 == "base")
	{
		sonuc = x * y;
		if (op3 == "+")
		{
			double temp = 0.0;
			temp = z + t;
			sonuc = ConvertFrom10(sonuc, temp);
		}
		else if (op3 == "-")
		{
			double temp = 0.0;
			temp = z - t;
			sonuc = ConvertFrom10(sonuc, temp);
		}
		else if (op3 == "*")
		{
			double temp = 0.0;
			temp = z * t;
			sonuc = ConvertFrom10(sonuc, temp);
		}
		else if (op3 == "/")
		{
			double temp = 0.0;
			temp = z / t;
			sonuc = ConvertFrom10(sonuc, temp);
		}
		else if (op3 == "%")
		{
			double temp = 0.0;
			temp = std::fmod(z, t);
			sonuc = std::fmod(sonuc, temp);
		}
		else if (op3 == "^")
		{
			double tmp1 = 1.0;
			for (int i = 0;i < t;++i)
			{
				tmp1 = tmp1 * z;

			}
			sonuc = ConvertFrom10(sonuc, tmp1);


		}
		else if (op3 == "base")
		{
			sonuc = ConvertFrom10(sonuc, z);
			sonuc = ConvertFrom10(sonuc, t);
		}
	}

	}
	else if (op1 == "/")
	{
	if (op2 == "^")
	{
		double tmp1 = 1.0;
		for (int i = 0;i < z;++i)
		{
			tmp1 = tmp1 * y;

		}
		if (op3 == "^")
		{
			int tmp2 = 1;
			for (int i = 0;i < t;++i)
			{
				tmp2 = tmp2 * tmp1;

			}
			sonuc = x / tmp2;

		}
		else
		{
			sonuc = x / tmp1;
			if (op3 == "+")
			{
				sonuc = sonuc + t;
			}
			else if (op3 == "-")
			{
				sonuc = sonuc - t;
			}
			else if (op3 == "*")
			{
				sonuc = sonuc * t;
			}
			else if (op3 == "/")
			{
				sonuc = sonuc / t;
			}
			else if (op3 == "%")
			{
				sonuc = std::fmod(sonuc, t);
			}
			else if (op3 == "base")
			{
				sonuc = ConvertFrom10(sonuc, t);
			}
		}
	}
	else if (op2 == "+")
	{
		sonuc = x / y;
		if (op3 == "+") {
			sonuc = sonuc + z;
			sonuc = sonuc + t;
		}
		else if (op3 == "-") {
			sonuc = sonuc + z;
			sonuc = sonuc - t;
		}
		else if (op3 == "*") {
			double temp = 0.0;
			temp = z * t;
			sonuc = sonuc + temp;
		}
		else if (op3 == "/") {
			double temp = 0.0;
			temp = z / t;
			sonuc = sonuc + temp;
		}
		else if (op3 == "%") {
			sonuc = sonuc + z;
			sonuc = std::fmod(sonuc, t);
		}
		else if (op3 == "^") {
			int tmp1 = 1;
			for (int i = 0;i < t;++i)
			{
				tmp1 = tmp1 * z;

			}
			sonuc = sonuc + tmp1;

		}
		else if (op3 == "base") {
			sonuc = sonuc + z;
			sonuc = ConvertFrom10(sonuc, t);
		}



	}
	else if (op2 == "-")
	{
		sonuc = x / y;
		if (op3 == "+") {
			sonuc = sonuc - z;
			sonuc = sonuc + t;
		}
		else if (op3 == "-") {
			sonuc = sonuc - z;
			sonuc = sonuc - t;
		}
		else if (op3 == "*") {
			double temp = 0.0;
			temp = z * t;
			sonuc = sonuc - temp;
		}
		else if (op3 == "/") {
			double temp = 0.0;
			temp = z / t;
			sonuc = sonuc - temp;
		}
		else if (op3 == "%") {
			sonuc = sonuc - z;
			sonuc = std::fmod(sonuc, t);
		}
		else if (op3 == "^") {
			double tmp1 = 1.0;
			for (int i = 0;i < t;++i)
			{
				tmp1 = tmp1 * z;

			}
			sonuc = sonuc - tmp1;

		}
		else if (op3 == "base") {
			sonuc = sonuc - z;
			sonuc = ConvertFrom10(sonuc, t);
		}

	}
	else if (op2 == "*")
	{
		sonuc = x / y;
		if (op3 == "+")
		{
			sonuc = sonuc * z;
			sonuc = sonuc + t;
		}
		else if (op3 == "-")
		{
			sonuc = sonuc * z;
			sonuc = sonuc - t;
		}
		else if (op3 == "*")
		{
			sonuc = sonuc * z;
			sonuc = sonuc * t;
		}
		else if (op3 == "/")
		{
			sonuc = sonuc * z;
			sonuc = sonuc / t;
		}
		else if (op3 == "^")
		{
			double tmp1 = 1.0;
			for (int i = 0;i < t;++i)
			{
				tmp1 = tmp1 * z;

			}
			sonuc = sonuc * tmp1;

		}
		else if (op3 == "base")
		{
			sonuc = sonuc * z;
			sonuc = ConvertFrom10(sonuc, t);
		}
		else if (op3 == "%")
		{
			sonuc = sonuc * z;
			sonuc = std::fmod(sonuc, t);

		}


	}
	else if (op2 == "/")
	{
		sonuc = x / y;
		if (op3 == "+")
		{
			sonuc = sonuc / z;
			sonuc = sonuc + t;
		}
		else if (op3 == "-")
		{
			sonuc = sonuc / z;
			sonuc = sonuc - t;
		}
		else if (op3 == "*")
		{
			sonuc = sonuc / z;
			sonuc = sonuc * t;
		}
		else if (op3 == "/")
		{
			sonuc = sonuc / z;
			sonuc = sonuc / t;
		}
		else if (op3 == "^")
		{
			double tmp1 = 1.0;
			for (int i = 0;i < t;++i)
			{
				tmp1 = tmp1 * z;

			}
			sonuc = sonuc / tmp1;

		}
		else if (op3 == "base")
		{
			sonuc = sonuc / z;
			sonuc = ConvertFrom10(sonuc, t);
		}
		else if (op3 == "%")
		{
			sonuc = sonuc / z;
			sonuc = std::fmod(sonuc, t);

		}
	}
	else if (op2 == "%")
	{
		sonuc = x / y;
		if (op3 == "+")
		{
			double temp = 0.0;
			temp = z + t;
			sonuc = std::fmod(sonuc, temp);
		}
		else if (op3 == "-")
		{
			double temp = 0.0;
			temp = z - t;
			sonuc = std::fmod(sonuc, temp);
		}
		else if (op3 == "*")
		{
			double temp = 0.0;
			temp = z * t;
			sonuc = std::fmod(sonuc, temp);
		}
		else if (op3 == "/")
		{
			double temp = 0.0;
			temp = z / t;
			sonuc = std::fmod(sonuc, temp);
		}
		else if (op3 == "%")
		{
			sonuc = std::fmod(sonuc, z);
			sonuc = std::fmod(sonuc, t);
		}
		else if (op3 == "^")
		{
			double tmp1 = 1.0;
			for (int i = 0;i < t;++i)
			{
				tmp1 = tmp1 * z;

			}
			sonuc = std::fmod(sonuc, tmp1);


		}
		else if (op3 == "base")
		{
			sonuc = std::fmod(sonuc, z);
			sonuc = ConvertFrom10(sonuc, t);
		}



	}
	else if (op2 == "base")
	{
		sonuc = x / y;
		if (op3 == "+")
		{
			double temp = 0.0;
			temp = z + t;
			sonuc = ConvertFrom10(sonuc, temp);
		}
		else if (op3 == "-")
		{
			double temp = 0.0;
			temp = z - t;
			sonuc = ConvertFrom10(sonuc, temp);
		}
		else if (op3 == "*")
		{
			double temp = 0.0;
			temp = z * t;
			sonuc = ConvertFrom10(sonuc, temp);
		}
		else if (op3 == "/")
		{
			double temp = 0.0;
			temp = z / t;
			sonuc = ConvertFrom10(sonuc, temp);
		}
		else if (op3 == "%")
		{
			double temp = 0.0;
			temp = std::fmod(z, t);
			sonuc = std::fmod(sonuc, temp);
		}
		else if (op3 == "^")
		{
			double tmp1 = 1.0;
			for (int i = 0;i < t;++i)
			{
				tmp1 = tmp1 * z;

			}
			sonuc = ConvertFrom10(sonuc, tmp1);


		}
		else if (op3 == "base")
		{
			sonuc = ConvertFrom10(sonuc, z);
			sonuc = ConvertFrom10(sonuc, t);
		}
	}


	}
	else if (op1 == "+" )
	{
	if (op2 == "^")
	{
		double tmp1 = 1.0;
		for (int i = 0;i < z;++i)
		{
			tmp1 = tmp1 * y;

		}
		if (op3 == "^")
		{
			int tmp2 = 1;
			for (int i = 0;i < t;++i)
			{
				tmp2 = tmp2 * tmp1;

			}
			sonuc = x + tmp2;

		}
		else
		{
			if (op3 == "+")
			{
				sonuc = tmp1 + x;
				sonuc = sonuc + t;
			}
			else if (op3 == "-")
			{
				sonuc = tmp1 + x;
				sonuc = sonuc - t;
			}
			else if (op3 == "*")
			{
				sonuc = tmp1 * t;
				sonuc = sonuc + x;
			}
			else if (op3 == "/")
			{
				sonuc = tmp1 / t;
				sonuc = sonuc + x;
			}
			else if (op3 == "%")
			{
				sonuc = x + tmp1;
				sonuc = std::fmod(sonuc, t);
			}
			else if (op3 == "base")
			{
				sonuc = x + tmp1;
				sonuc = ConvertFrom10(sonuc, t);
			}
		}
	}
	else if (op2 == "+")
	{
		if (op3 == "+") {
			sonuc = x + y;
			sonuc = sonuc + z;
			sonuc = sonuc + t;
		}
		else if (op3 == "-") {
			sonuc = x + y;
			sonuc = sonuc + z;
			sonuc = sonuc - t;
		}
		else if (op3 == "*") {
			double temp = 0.0;
			temp = z * t;
			sonuc = x + y;
			sonuc = sonuc + temp;
		}
		else if (op3 == "/") {
			double temp = 0.0;
			temp = z / t;
			sonuc = x + y;
			sonuc = sonuc + temp;
		}
		else if (op3 == "%") {
			sonuc = x + y;
			sonuc = sonuc + z;
			sonuc = std::fmod(sonuc, t);
		}
		else if (op3 == "^") {
			int tmp1 = 1;
			for (int i = 0;i < t;++i)
			{
				tmp1 = tmp1 * z;

			}
			sonuc = x + y;
			sonuc = sonuc + tmp1;

		}
		else if (op3 == "base") {
			sonuc = x + y;
			sonuc = sonuc + z;
			sonuc = ConvertFrom10(sonuc, t);
		}



	}
	else if (op2 == "-")
	{
	if (op3 == "+") {
		sonuc = x + y;
		sonuc = sonuc - z;
		sonuc = sonuc + t;
	}
	else if (op3 == "-") {
		sonuc = x + y;
		sonuc = sonuc - z;
		sonuc = sonuc - t;
	}
	else if (op3 == "*") {
		double temp = 0.0;
		temp = z * t;
		sonuc = x + y;
		sonuc = sonuc - temp;
	}
	else if (op3 == "/") {
		double temp = 0.0;
		temp = z / t;
		sonuc = x - y;
		sonuc = sonuc + temp;
	}
	else if (op3 == "%") {
		sonuc = x + y;
		sonuc = sonuc - z;
		sonuc = std::fmod(sonuc, t);
	}
	else if (op3 == "^") {
		int tmp1 = 1;
		for (int i = 0;i < t;++i)
		{
			tmp1 = tmp1 * z;

		}
		sonuc = x + y;
		sonuc = sonuc - tmp1;

	}
	else if (op3 == "base") {
		sonuc = x + y;
		sonuc = sonuc - z;
		sonuc = ConvertFrom10(sonuc, t);
	}

	}
	else if (op2 == "*")
	{
	
		if (op3 == "+")
		{
			double temp = 0.0;
			temp = y * z;
			sonuc = x + temp;
			sonuc = sonuc + t;
		}
		else if (op3 == "-")
		{
			double temp = 0.0;
			temp = y * z;
			sonuc = x + temp;
			sonuc = sonuc - t;
	
		}
		else if (op3 == "*")
		{
			double temp = 0.0;
			temp = y * z;
			sonuc = t * temp;
			sonuc = sonuc + x;
		}
		else if (op3 == "/")
		{
			double temp = 0.0;
			temp = y * z;
			sonuc = temp / t;
			sonuc = sonuc + x;
		}
		else if (op3 == "^")
		{
			double tmp1 = 1.0;
			for (int i = 0;i < t;++i)
			{
				tmp1 = tmp1 * z;

			}
			sonuc = tmp1 * y;
			sonuc = x + sonuc;

		}
		else if (op3 == "base")
		{
			double temp = 0.0;
			temp = y * z;
			sonuc = x + temp;
			sonuc = ConvertFrom10(sonuc, t);
		}
		else if (op3 == "%")
		{
			double temp = 0.0;
			temp = y * z;
			sonuc = x + temp;
			sonuc = std::fmod(sonuc, t);

		}


	}
	else if (op2 == "/")
	{
	if (op3 == "+")
	{
		double temp = 0.0;
		temp = y / z;
		sonuc = x + temp;
		sonuc = sonuc + t;
	}
	else if (op3 == "-")
	{
		double temp = 0.0;
		temp = y / z;
		sonuc = x + temp;
		sonuc = sonuc - t;

	}
	else if (op3 == "*")
	{
		double temp = 0.0;
		temp = y / z;
		sonuc = t * temp;
		sonuc = sonuc + x;
	}
	else if (op3 == "/")
	{
		double temp = 0.0;
		temp = y / z;
		sonuc = temp / t;
		sonuc = sonuc + x;
	}
	else if (op3 == "^")
	{
		double tmp1 = 1.0;
		for (int i = 0;i < t;++i)
		{
			tmp1 = tmp1 * z;

		}
		sonuc = y / tmp1 ;
		sonuc = x + sonuc;

	}
	else if (op3 == "base")
	{
		double temp = 0.0;
		temp = y / z;
		sonuc = x + temp;
		sonuc = ConvertFrom10(sonuc, t);
	}
	else if (op3 == "%")
	{
		double temp = 0.0;
		temp = y / z;
		sonuc = x + temp;
		sonuc = std::fmod(sonuc, t);

	}
	}
	else if (op2 == "%")
	{
		if (op3 == "+")
		{
			double temp = 0.0;
			temp = z + t;
			sonuc = x + y;
			sonuc = std::fmod(sonuc, temp);
		}
		else if (op3 == "-")
		{
			double temp = 0.0;
			sonuc = x + y;
			temp = z - t;
			sonuc = std::fmod(sonuc, temp);
		}
		else if (op3 == "*")
		{
			double temp = 0.0;
			sonuc = x + y;
			temp = z * t;
			sonuc = std::fmod(sonuc, temp);
		}
		else if (op3 == "/")
		{
			sonuc = x + y;
			double temp = 0.0;
			temp = z / t;
			sonuc = std::fmod(sonuc, temp);
		}
		else if (op3 == "%")
		{
			sonuc = x + y;
			sonuc = std::fmod(sonuc, z);
			sonuc = std::fmod(sonuc, t);
		}
		else if (op3 == "^")
		{
			double tmp1 = 1.0;
			for (int i = 0;i < t;++i)
			{
				tmp1 = tmp1 * z;

			}
			sonuc = x + y;
			sonuc = std::fmod(sonuc, tmp1);


		}
		else if (op3 == "base")
		{
			sonuc = x + y;
			sonuc = std::fmod(sonuc, z);
			sonuc = ConvertFrom10(sonuc, t);
		}



	}
	else if (op2 == "base")
	{
	if (op3 == "+")
	{
		double temp = 0.0;
		temp = z + t;
		sonuc = x + y;
		sonuc = ConvertFrom10(sonuc, temp);
	}
	else if (op3 == "-")
	{
		double temp = 0.0;
		temp = z - t;
		sonuc = x + y;
		sonuc = ConvertFrom10(sonuc, temp);
	}
	else if (op3 == "*")
	{
		double temp = 0.0;
		temp = z * t;
		sonuc = x + y;
		sonuc = ConvertFrom10(sonuc, temp);
	}
	else if (op3 == "/")
	{
		double temp = 0.0;
		temp = z / t;
		sonuc = x + y;
		sonuc = ConvertFrom10(sonuc, temp);
	}
	else if (op3 == "%")
	{
		double temp = 0.0;
		temp = std::fmod(z, t);
		sonuc = x + y;
		sonuc = std::fmod(sonuc, temp);
	}
	else if (op3 == "^")
	{
		double tmp1 = 1.0;
		for (int i = 0;i < t;++i)
		{
			tmp1 = tmp1 * z;

		}
		sonuc = x + y;
		sonuc = ConvertFrom10(sonuc, tmp1);


	}
	else if (op3 == "base")
	{
		sonuc = x + y;
		sonuc = ConvertFrom10(sonuc, z);
		sonuc = ConvertFrom10(sonuc, t);
	}
	}


	}
	else if (op1 == "-")
	{
	if (op2 == "^")
	{
		double tmp1 = 1.0;
		for (int i = 0;i < z;++i)
		{
			tmp1 = tmp1 * y;

		}
		if (op3 == "^")
		{
			int tmp2 = 1;
			for (int i = 0;i < t;++i)
			{
				tmp2 = tmp2 * tmp1;

			}
			sonuc = x - tmp2;

		}
		else
		{
			if (op3 == "+")
			{
				sonuc = x - tmp1 ;
				sonuc = sonuc + t;
			}
			else if (op3 == "-")
			{
				sonuc = x - tmp1;
				sonuc = sonuc - t;
			}
			else if (op3 == "*")
			{
				sonuc = tmp1 * t;
				sonuc = x - sonuc;
			}
			else if (op3 == "/")
			{
				sonuc = tmp1 / t;
				sonuc = x - sonuc;
			}
			else if (op3 == "%")
			{
				sonuc = x - tmp1;
				sonuc = std::fmod(sonuc, t);
			}
			else if (op3 == "base")
			{
				sonuc = x - tmp1;
				sonuc = ConvertFrom10(sonuc, t);
			}
		}
	}
	else if (op2 == "+")
	{
		if (op3 == "+") {
			sonuc = x - y;
			sonuc = sonuc + z;
			sonuc = sonuc + t;
		}
		else if (op3 == "-") {
			sonuc = x - y;
			sonuc = sonuc + z;
			sonuc = sonuc - t;
		}
		else if (op3 == "*") {
			double temp = 0.0;
			temp = z * t;
			sonuc = x - y;
			sonuc = sonuc + temp;
		}
		else if (op3 == "/") {
			double temp = 0.0;
			temp = z / t;
			sonuc = x - y;
			sonuc = sonuc + temp;
		}
		else if (op3 == "%") {
			sonuc = x - y;
			sonuc = sonuc + z;
			sonuc = std::fmod(sonuc, t);
		}
		else if (op3 == "^") {
			int tmp1 = 1;
			for (int i = 0;i < t;++i)
			{
				tmp1 = tmp1 * z;

			}
			sonuc = x - y;
			sonuc = sonuc + tmp1;

		}
		else if (op3 == "base") {
			sonuc = x - y;
			sonuc = sonuc + z;
			sonuc = ConvertFrom10(sonuc, t);
		}



	}
	else if (op2 == "-")
	{
		if (op3 == "+") {
			sonuc = x - y;
			sonuc = sonuc - z;
			sonuc = sonuc + t;
		}
		else if (op3 == "-") {
			sonuc = x - y;
			sonuc = sonuc - z;
			sonuc = sonuc - t;
		}
		else if (op3 == "*") {
			double temp = 0.0;
			temp = z * t;
			sonuc = x - y;
			sonuc = sonuc + temp;
		}
		else if (op3 == "/") {
			double temp = 0.0;
			temp = z / t;
			sonuc = x - y;
			sonuc = sonuc + temp;
		}
		else if (op3 == "%") {
			sonuc = x - y;
			sonuc = sonuc - z;
			sonuc = std::fmod(sonuc, t);
		}
		else if (op3 == "^") {
			int tmp1 = 1;
			for (int i = 0;i < t;++i)
			{
				tmp1 = tmp1 * z;

			}
			sonuc = x - y;
			sonuc = sonuc - tmp1;

		}
		else if (op3 == "base") {
			sonuc = x - y;
			sonuc = sonuc - z;
			sonuc = ConvertFrom10(sonuc, t);
		}

	}
	else if (op2 == "*")
	{

		if (op3 == "+")
		{
			double temp = 0.0;
			temp = y * z;
			sonuc = x - temp;
			sonuc = sonuc + t;
		}
		else if (op3 == "-")
		{
			double temp = 0.0;
			temp = y * z;
			sonuc = x - temp;
			sonuc = sonuc - t;

		}
		else if (op3 == "*")
		{
			double temp = 0.0;
			temp = y * z;
			sonuc = t * temp;
			sonuc = x - sonuc;
		}
		else if (op3 == "/")
		{
			double temp = 0.0;
			temp = y * z;
			sonuc = temp / t;
			sonuc = x - sonuc;
		}
		else if (op3 == "^")
		{
			double tmp1 = 1.0;
			for (int i = 0;i < t;++i)
			{
				tmp1 = tmp1 * z;

			}
			sonuc = tmp1 * y;
			sonuc = x - sonuc;

		}
		else if (op3 == "base")
		{
			double temp =  y * z;
			sonuc = x - temp;
			sonuc = ConvertFrom10(sonuc, t);
		}
		else if (op3 == "%")
		{
			double temp = 0.0;
			temp = y * z;
			sonuc = x - temp;
			sonuc = std::fmod(sonuc, t);

		}


	}
	else if (op2 == "/")
	{
		if (op3 == "+")
		{
			double temp = 0.0;
			temp = y / z;
			sonuc = x - temp;
			sonuc = sonuc + t;
		}
		else if (op3 == "-")
		{
			double temp = 0.0;
			temp = y / z;
			sonuc = x - temp;
			sonuc = sonuc - t;

		}
		else if (op3 == "*")
		{
			double temp = 0.0;
			temp = y / z;
			sonuc = t * temp;
			sonuc = x - sonuc;
		}
		else if (op3 == "/")
		{
			double temp = 0.0;
			temp = y / z;
			sonuc = temp / t;
			sonuc = x - sonuc;
		}
		else if (op3 == "^")
		{
			double tmp1 = 1.0;
			for (int i = 0;i < t;++i)
			{
				tmp1 = tmp1 * z;

			}
			sonuc = y / tmp1;
			sonuc = x - sonuc;

		}
		else if (op3 == "base")
		{
			double temp = y / z;
			sonuc = x - temp;
			sonuc = ConvertFrom10(sonuc, t);
		}
		else if (op3 == "%")
		{
			double temp = 0.0;
			temp = y / z;
			sonuc = x - temp;
			sonuc = std::fmod(sonuc, t);

		}
	}
	else if (op2 == "%")
	{
		if (op3 == "+")
		{
			double temp = 0.0;
			temp = z + t;
			sonuc = x - y;
			sonuc = std::fmod(sonuc, temp);
		}
		else if (op3 == "-")
		{
			double temp = 0.0;
			sonuc = x - y;
			temp = z - t;
			sonuc = std::fmod(sonuc, temp);
		}
		else if (op3 == "*")
		{
			double temp = 0.0;
			sonuc = x - y;
			temp = z * t;
			sonuc = std::fmod(sonuc, temp);
		}
		else if (op3 == "/")
		{
			sonuc = x - y;
			double temp = 0.0;
			temp = z / t;
			sonuc = std::fmod(sonuc, temp);
		}
		else if (op3 == "%")
		{
			sonuc = x - y;
			sonuc = std::fmod(sonuc, z);
			sonuc = std::fmod(sonuc, t);
		}
		else if (op3 == "^")
		{
			double tmp1 = 1.0;
			for (int i = 0;i < t;++i)
			{
				tmp1 = tmp1 * z;

			}
			sonuc = x - y;
			sonuc = std::fmod(sonuc, tmp1);


		}
		else if (op3 == "base")
		{
			sonuc = x - y;
			sonuc = std::fmod(sonuc, z);
			sonuc = ConvertFrom10(sonuc, t);
		}



	}
	else if (op2 == "base")
	{
	if (op3 == "+")
	{
		double temp = 0.0;
		temp = z + t;
		sonuc = x - y;
		sonuc = ConvertFrom10(sonuc, temp);
	}
	else if (op3 == "-")
	{
		double temp = 0.0;
		temp = z - t;
		sonuc = x - y;
		sonuc = ConvertFrom10(sonuc, temp);
	}
	else if (op3 == "*")
	{
		double temp = 0.0;
		temp = z * t;
		sonuc = x - y;
		sonuc = ConvertFrom10(sonuc, temp);
	}
	else if (op3 == "/")
	{
		double temp = 0.0;
		temp = z / t;
		sonuc = x - y;
		sonuc = ConvertFrom10(sonuc, temp);
	}
	else if (op3 == "%")
	{
		double temp = 0.0;
		temp = std::fmod(z, t);
		sonuc = x + y;
		sonuc = std::fmod(sonuc, temp);
	}
	else if (op3 == "^")
	{
		double tmp1 = 1.0;
		for (int i = 0;i < t;++i)
		{
			tmp1 = tmp1 * z;

		}
		sonuc = x - y;
		sonuc = ConvertFrom10(sonuc, tmp1);


	}
	else if (op3 == "base")
	{
		sonuc = x - y;
		sonuc = ConvertFrom10(sonuc, z);
		sonuc = ConvertFrom10(sonuc, t);
	}
	}


	}
	else if (op1 == "%") {
	if (op2 == "^")
	{
		double tmp1 = 1.0;
		for (int i = 0;i < z;++i)
		{
			tmp1 = tmp1 * y;

		}
		if (op3 == "^")
		{
			double tmp2 = 1.0;
			for (int i = 0;i < t;++i)
			{
				tmp2 = tmp2 * tmp1;

			}
			sonuc = std::fmod(x,tmp2);

		}
		else
		{
			if (op3 == "+")
			{
				sonuc = tmp1 + t;
				sonuc = std::fmod(x, sonuc);
				
			}
			else if (op3 == "-")
			{
				sonuc = tmp1 - t;
				sonuc = std::fmod(x, sonuc);
			}
			else if (op3 == "*")
			{
				sonuc = tmp1 * t;
				sonuc = std::fmod(x, sonuc);
			}
			else if (op3 == "/")
			{
				sonuc = tmp1 / t;
				sonuc = std::fmod(x, sonuc);
			}
			else if (op3 == "%")
			{
				sonuc = std::fmod(x, tmp1);
				sonuc = std::fmod(sonuc, t);
			}
			else if (op3 == "base")
			{
				sonuc = std::fmod(x, tmp1);
				sonuc = ConvertFrom10(sonuc, t);
			}
		}
	}
	else if (op2 == "+")
	{
		if (op3 == "+") {
			
			sonuc = y + z;
			sonuc = sonuc + t;
			sonuc = std::fmod(x, sonuc);
		}
		else if (op3 == "-") {
			sonuc = y + z;
			sonuc = sonuc - t;
			sonuc = std::fmod(x, sonuc);
		}
		else if (op3 == "*") {
			double temp = 0.0;
			temp = z * t;
			sonuc = y + temp;
			sonuc = std::fmod(x, sonuc);
		}
		else if (op3 == "/") {
			double temp = 0.0;
			temp = z / t;
			sonuc = y + temp;
			sonuc = std::fmod(x, sonuc);
		}
		else if (op3 == "%") {
			sonuc = y + z;
			sonuc = std::fmod(x, sonuc);
			sonuc = std::fmod(sonuc, t);
		}
		else if (op3 == "^") {
			double  tmp1 = 1.0;
			for (int i = 0;i < t;++i)
			{
				tmp1 = tmp1 * z;

			}
			sonuc = y + tmp1;
			sonuc = std::fmod(x, sonuc);

		}
		else if (op3 == "base") {
			double temp = y + z;
			sonuc = std::fmod(x, temp);
			sonuc = ConvertFrom10(sonuc, t);
		}



	}
	else if (op2 == "-")
	{
	if (op3 == "+") {

		sonuc = y - z;
		sonuc = sonuc + t;
		sonuc = std::fmod(x, sonuc);
	}
	else if (op3 == "-") {
		sonuc = y - z;
		sonuc = sonuc - t;
		sonuc = std::fmod(x, sonuc);
	}
	else if (op3 == "*") {
		double temp = 0.0;
		temp = z * t;
		sonuc = y - temp;
		sonuc = std::fmod(x, sonuc);
	}
	else if (op3 == "/") {
		double temp = 0.0;
		temp = z / t;
		sonuc = y - temp;
		sonuc = std::fmod(x, sonuc);
	}
	else if (op3 == "%") {
		sonuc = y - z;
		sonuc = std::fmod(x, sonuc);
		sonuc = std::fmod(sonuc, t);
	}
	else if (op3 == "^") {
		double  tmp1 = 1.0;
		for (int i = 0;i < t;++i)
		{
			tmp1 = tmp1 * z;

		}
		sonuc = y - tmp1;
		sonuc = std::fmod(x, sonuc);

	}
	else if (op3 == "base") {
		double temp = y - z;
		sonuc = std::fmod(x, temp);
		sonuc = ConvertFrom10(sonuc, t);
	}

	}
	else if (op2 == "*")
	{

	if (op3 == "+") {

		sonuc = y * z;
		sonuc = sonuc + t;
		sonuc = std::fmod(x, sonuc);
	}
	else if (op3 == "-") {
		sonuc = y * z;
		sonuc = sonuc - t;
		sonuc = std::fmod(x, sonuc);
	}
	else if (op3 == "*") {
		double temp = 0.0;
		temp = z * t;
		sonuc = y * temp;
		sonuc = std::fmod(x, sonuc);
	}
	else if (op3 == "/") {
		double temp = 0.0;
		temp = y * z;
		sonuc = temp / t;
		sonuc = std::fmod(x, sonuc);
	}
	else if (op3 == "%") {
		sonuc = y * z;
		sonuc = std::fmod(x, sonuc);
		sonuc = std::fmod(sonuc, t);
	}
	else if (op3 == "^") {
		double  tmp1 = 1.0;
		for (int i = 0;i < t;++i)
		{
			tmp1 = tmp1 * z;

		}
		sonuc = y * tmp1;
		sonuc = std::fmod(x, sonuc);

	}
	else if (op3 == "base") {
		double temp = y * z;
		sonuc = std::fmod(x, temp);
		sonuc = ConvertFrom10(sonuc, t);
	}


	}
	else if (op2 == "/")
	{
	if (op3 == "+") {

		sonuc = y / z;
		sonuc = sonuc + t;
		sonuc = std::fmod(x, sonuc);
	}
	else if (op3 == "-") {
		sonuc = y / z;
		sonuc = sonuc - t;
		sonuc = std::fmod(x, sonuc);
	}
	else if (op3 == "*") {
		double temp = 0.0;
		temp = y / z;
		sonuc = temp * t;
	
		sonuc = std::fmod(x, sonuc);
	}
	else if (op3 == "/") {
		double temp = 0.0;
		temp = y / z;
		sonuc = temp / t;
		sonuc = std::fmod(x, sonuc);
	}
	else if (op3 == "%") {
		sonuc = y / z;
		sonuc = std::fmod(x, sonuc);
		sonuc = std::fmod(sonuc, t);
	}
	else if (op3 == "^") {
		double  tmp1 = 1.0;
		for (int i = 0;i < t;++i)
		{
			tmp1 = tmp1 * z;

		}
		sonuc = y / tmp1;
		sonuc = std::fmod(x, sonuc);

	}
	else if (op3 == "base") {
		double temp = y / z;
		sonuc = std::fmod(x, temp);
		sonuc = ConvertFrom10(sonuc, t);
	}
	}
	else if (op2 == "%")
	{
		if (op3 == "+")
		{
			double temp = 0.0;
			temp = z + t;
			sonuc = std::fmod(x, y);
			sonuc = std::fmod(sonuc,temp);
		}
		else if (op3 == "-")
		{
			double temp = 0.0;
			temp = z - t;
			sonuc = std::fmod(x, y);
			sonuc = std::fmod(sonuc, temp);
	
		}
		else if (op3 == "*")
		{
			double temp = 0.0;
			temp = z * t;
			sonuc = std::fmod(x, y);
			sonuc = std::fmod(sonuc, temp);
		
		}
		else if (op3 == "/")
		{
			double temp = 0.0;
			temp = z / t;
			sonuc = std::fmod(x, y);
			sonuc = std::fmod(sonuc, temp);
		}
		else if (op3 == "%")
		{
			sonuc = std::fmod(x,y);
			sonuc = std::fmod(sonuc, z);
			sonuc = std::fmod(sonuc, t);
		}
		else if (op3 == "^")
		{
			double tmp1 = 1.0;
			for (int i = 0;i < t;++i)
			{
				tmp1 = tmp1 * z;

			}
			sonuc = std::fmod(x,y);
			sonuc = std::fmod(sonuc, tmp1);


		}
		else if (op3 == "base")
		{
			sonuc = std::fmod(x, y);
			sonuc = std::fmod(sonuc, z);
			sonuc = ConvertFrom10(sonuc, t);
		}



	}
	else if (op2 == "base")
	{
	if (op3 == "+")
	{
		double temp = 0.0;
		temp = z + t;
		sonuc = std::fmod(x, y);
		sonuc = ConvertFrom10(sonuc, temp);
	}
	else if (op3 == "-")
	{
		double temp = 0.0;
		temp = z - t;
		sonuc = std::fmod(x, y);
		sonuc = ConvertFrom10(sonuc, temp);


	}
	else if (op3 == "*")
	{
		double temp = 0.0;
		temp = z * t;
		sonuc = std::fmod(x, y);
		sonuc = ConvertFrom10(sonuc, temp);

	}
	else if (op3 == "/")
	{
		double temp = 0.0;
		temp = z / t;
		sonuc = std::fmod(x, y);
		sonuc = ConvertFrom10(sonuc, temp);
	}
	else if (op3 == "%")
	{
		double temp = 0.0;
		sonuc = std::fmod(x, y);
		temp = std::fmod(z,t);
		sonuc = ConvertFrom10(sonuc, temp);
	}
	else if (op3 == "^")
	{
		double tmp1 = 1.0;
		for (int i = 0;i < t;++i)
		{
			tmp1 = tmp1 * z;

		}
		sonuc = std::fmod(x, y);
		sonuc = ConvertFrom10(sonuc, tmp1);


	}
	else if (op3 == "base")
	{
		sonuc = std::fmod(x, y);
		sonuc = ConvertFrom10(sonuc, z);
		sonuc = ConvertFrom10(sonuc, t);
	}
	}


    }
	else if (op1 == "base") {
	if (op2 == "^")
	{
		double tmp1 = 1.0;
		for (int i = 0;i < z;++i)
		{
			tmp1 = tmp1 * y;

		}
		if (op3 == "^")
		{
			double tmp2 = 1.0;
			for (int i = 0;i < t;++i)
			{
				tmp2 = tmp2 * tmp1;

			}
			sonuc = ConvertFrom10(x, tmp2);

		}
		else
		{
			if (op3 == "+")
			{
				sonuc = tmp1 + t;
				sonuc = ConvertFrom10(x, sonuc);
			}
			else if (op3 == "-")
			{
				sonuc = tmp1 - t;
				sonuc = ConvertFrom10(x, sonuc);
			}
			else if (op3 == "*")
			{
				sonuc = tmp1 * t;
				sonuc = ConvertFrom10(x, tmp1);
			}
			else if (op3 == "/")
			{
				sonuc = tmp1 / t;
				sonuc = ConvertFrom10(x, tmp1);
			}
			else if (op3 == "%")
			{
				sonuc = std::fmod(tmp1, t);
				sonuc = ConvertFrom10(x, sonuc);
			}
			else if (op3 == "base")
			{
				sonuc = ConvertFrom10(x, sonuc);
				sonuc = ConvertFrom10(sonuc, t);
			}
		}
	}
	else if (op2 == "+")
	{
		if (op3 == "+") {

			sonuc = y + z;
			sonuc = sonuc + t;
			sonuc = ConvertFrom10(x, sonuc);
		}
		else if (op3 == "-") {
			sonuc = y + z;
			sonuc = sonuc - t;
			sonuc = ConvertFrom10(x, sonuc);
		}
		else if (op3 == "*") {
			double temp = 0.0;
			temp = z * t;
			sonuc = y + temp;
			sonuc = ConvertFrom10(x, sonuc);
		}
		else if (op3 == "/") {
			double temp = 0.0;
			temp = z / t;
			sonuc = y + temp;
			sonuc = ConvertFrom10(x, sonuc);
		}
		else if (op3 == "%") {
			sonuc = y + z;
			sonuc = std::fmod(sonuc, t);
			sonuc = ConvertFrom10(x, sonuc);
			
		}
		else if (op3 == "^") {
			double  tmp1 = 1.0;
			for (int i = 0;i < t;++i)
			{
				tmp1 = tmp1 * z;

			}
			sonuc = y + tmp1;
			sonuc = ConvertFrom10(x, sonuc);

		}
		else if (op3 == "base") {
			double temp = y + z;
			sonuc = ConvertFrom10(x, temp);
			sonuc = ConvertFrom10(sonuc, t);
		}



	}
	else if (op2 == "-")
	{
		if (op3 == "+") {

			sonuc = y - z;
			sonuc = sonuc + t;
			sonuc = ConvertFrom10(x, sonuc);
		}
		else if (op3 == "-") {
			sonuc = y - z;
			sonuc = sonuc - t;
			sonuc = ConvertFrom10(x, sonuc);
		}
		else if (op3 == "*") {
			double temp = 0.0;
			temp = z * t;
			sonuc = y - temp;
			sonuc = ConvertFrom10(x, sonuc);
		}
		else if (op3 == "/") {
			double temp = 0.0;
			temp = z / t;
			sonuc = y - temp;
			sonuc = ConvertFrom10(x, sonuc);
		}
		else if (op3 == "%") {
			sonuc = y - z;
			sonuc = std::fmod(sonuc, t);
			sonuc = ConvertFrom10(x, sonuc);
			
		}
		else if (op3 == "^") {
			double  tmp1 = 1.0;
			for (int i = 0;i < t;++i)
			{
				tmp1 = tmp1 * z;

			}
			sonuc = y - tmp1;
			sonuc = ConvertFrom10(x, sonuc);

		}
		else if (op3 == "base") {
			double temp = y - z;
			sonuc = ConvertFrom10(x, temp);
			sonuc = ConvertFrom10(sonuc, t);
		}

	}
	else if (op2 == "*")
	{

		if (op3 == "+") {

			sonuc = y * z;
			sonuc = sonuc + t;
			sonuc = ConvertFrom10(x, sonuc);
		}
		else if (op3 == "-") {
			sonuc = y * z;
			sonuc = sonuc - t;
			sonuc = ConvertFrom10(x, sonuc);
		}
		else if (op3 == "*") {
			double temp = 0.0;
			temp = z * t;
			sonuc = y * temp;
			sonuc = ConvertFrom10(x, sonuc);
		}
		else if (op3 == "/") {
			double temp = 0.0;
			temp = y * z;
			sonuc = temp / t;
			sonuc = ConvertFrom10(x, sonuc);
		}
		else if (op3 == "%") {
			sonuc = y * z;
			sonuc = std::fmod(sonuc, t);
			sonuc = ConvertFrom10(x, sonuc);
			
		}
		else if (op3 == "^") {
			double  tmp1 = 1.0;
			for (int i = 0;i < t;++i)
			{
				tmp1 = tmp1 * z;

			}
			sonuc = y * tmp1;
			sonuc = ConvertFrom10(x, sonuc);

		}
		else if (op3 == "base") {
			double temp = y * z;
			sonuc = ConvertFrom10(x, temp);
			sonuc = ConvertFrom10(sonuc, t);
		}


	}
	else if (op2 == "/")
	{
		if (op3 == "+") {

			sonuc = y / z;
			sonuc = sonuc + t;
			sonuc = ConvertFrom10(x, sonuc);
		}
		else if (op3 == "-") {
			sonuc = y / z;
			sonuc = sonuc - t;
			sonuc = ConvertFrom10(x, sonuc);
		}
		else if (op3 == "*") {
			double temp = 0.0;
			temp = y / z;
			sonuc = temp * t;

			sonuc = ConvertFrom10(x, sonuc);
		}
		else if (op3 == "/") {
			double temp = 0.0;
			temp = y / z;
			sonuc = temp / t;
			sonuc = ConvertFrom10(x, sonuc);
		}
		else if (op3 == "%") {
			sonuc = y / z;
			sonuc = std::fmod(sonuc, t);
			sonuc = ConvertFrom10(x, sonuc);
			
		}
		else if (op3 == "^") {
			double  tmp1 = 1.0;
			for (int i = 0;i < t;++i)
			{
				tmp1 = tmp1 * z;

			}
			sonuc = y / tmp1;
			sonuc = ConvertFrom10(x, sonuc);

		}
		else if (op3 == "base") {
			double temp = y / z;
			sonuc = ConvertFrom10(x, temp);
			sonuc = ConvertFrom10(sonuc, t);
		}
	}
	else if (op2 == "%")
	{
		if (op3 == "+")
		{
			double temp = 0.0;
			temp = z + t;
			sonuc = std::fmod(y, temp);
			sonuc = ConvertFrom10(x,sonuc);
		}
		else if (op3 == "-")
		{
			double temp = 0.0;
			temp = z - t;
			sonuc = std::fmod(y, temp);
			sonuc = ConvertFrom10(x, sonuc);

		}
		else if (op3 == "*")
		{
			double temp = 0.0;
			temp = z * t;
			sonuc = std::fmod(y, temp);
			sonuc = ConvertFrom10(x, sonuc);

		}
		else if (op3 == "/")
		{
			double temp = 0.0;
			temp = z / t;
			sonuc = std::fmod(y, temp);
			sonuc = ConvertFrom10(x, sonuc);
		}
		else if (op3 == "%")
		{
			sonuc = std::fmod(y, z);
			sonuc = std::fmod(sonuc, t);
			sonuc = ConvertFrom10(x, sonuc);
		}
		else if (op3 == "^")
		{
			double tmp1 = 1.0;
			for (int i = 0;i < t;++i)
			{
				tmp1 = tmp1 * z;

			}
			sonuc = std::fmod(y, tmp1);
			sonuc = ConvertFrom10(x, sonuc);


		}
		else if (op3 == "base")
		{
			double temp = std::fmod(y, z);
			sonuc = ConvertFrom10(x,temp);
			sonuc = ConvertFrom10(sonuc,t);
		}



	}
	else if (op2 == "base")
	{
		if (op3 == "+")
		{
			double temp = 0.0;
			temp = z + t;
			sonuc = ConvertFrom10(x, y);
			sonuc = ConvertFrom10(sonuc, temp);
		}
		else if (op3 == "-")
		{
			double temp = 0.0;
			temp = z - t;
			sonuc = ConvertFrom10(x, y);
			sonuc = ConvertFrom10(sonuc, temp);
		


		}
		else if (op3 == "*")
		{
			double temp = 0.0;
			temp = z * t;
			sonuc = ConvertFrom10(x, y);
			sonuc = ConvertFrom10(sonuc, temp);

		}
		else if (op3 == "/")
		{
			double temp = 0.0;
			temp = z / t;
			sonuc = ConvertFrom10(x, y);
			sonuc = ConvertFrom10(sonuc, temp);
		}
		else if (op3 == "%")
		{
			double temp = 0.0;
			temp = std::fmod(z, t);
			sonuc = ConvertFrom10(x, y);
			sonuc = ConvertFrom10(sonuc, temp);

		}
		else if (op3 == "^")
		{
			double tmp1 = 1.0;
			for (int i = 0;i < t;++i)
			{
				tmp1 = tmp1 * z;

			}
			sonuc = ConvertFrom10(x, y);
			sonuc = ConvertFrom10(sonuc, tmp1);


		}
		else if (op3 == "base")
		{
			sonuc = ConvertFrom10(x, y);
			sonuc = ConvertFrom10(sonuc, z);
			sonuc = ConvertFrom10(sonuc, t);
		}
	}

	}
	return sonuc;
}

