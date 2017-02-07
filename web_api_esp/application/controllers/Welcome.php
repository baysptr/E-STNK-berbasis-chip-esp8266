<?php
defined('BASEPATH') OR exit('No direct script access allowed');

class Welcome extends CI_Controller {

	/**
	 * Index Page for this controller.
	 *
	 * Maps to the following URL
	 * 		http://example.com/index.php/welcome
	 *	- or -
	 * 		http://example.com/index.php/welcome/index
	 *	- or -
	 * Since this controller is set as the default controller in
	 * config/routes.php, it's displayed at http://example.com/
	 *
	 * So any other public methods not prefixed with an underscore will
	 * map to /index.php/welcome/<method_name>
	 * @see https://codeigniter.com/user_guide/general/urls.html
	 */
	public function index()
	{
		$this->load->view('welcome_message');
	}

	public function testing()
	{
		$result = array();
		$result[] = array("data-ssid" => array("nama-ssid" => "nopol", "password-ssid" => "bayu_ganteng"), "data-stnk" => array("nopol" => "L 6125 QZ", "masa-pajak" => "2018", "masa-stnk" => "2020"));

		print_r(json_encode($result));
	}
}
